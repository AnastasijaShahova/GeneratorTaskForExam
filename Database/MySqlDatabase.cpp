#include "MySqlDatabase.h"

MySQLStatement::MySQLStatement(MySQLDatabase &db, const char *sql, const uint32_t prefetchRows)
: db_(&db)
{
    unsigned long sz = static_cast<unsigned long>(strlen(sql));
#if _DEBUG
    stmtQuery_ = sql;
#endif

    stmt_ = mysql_stmt_init(db_->getDB());

    if (!stmt_) {
        throwException();
    }

    useCursor_ = queryForCursor(sql);

    if (useCursor_) {
        const unsigned long type = CURSOR_TYPE_READ_ONLY;
        if (mysql_stmt_attr_set(stmt_, STMT_ATTR_CURSOR_TYPE, &type)) {
            throwException();
        }

        if (!(prefetchRows > 0)) {
            throw std::logic_error{"Number of rows to fetch from server should be more than 0."};
        }
        const unsigned long prefetch_rows = prefetchRows;
        if (mysql_stmt_attr_set(stmt_, STMT_ATTR_PREFETCH_ROWS, &prefetch_rows)) {
            throwException();
        }
    }

    if (mysql_stmt_prepare(stmt_, sql, sz)) {
        throwException();
    }

    bindCount_ = mysql_stmt_param_count(stmt_);

    if (bindCount_ > 0) {
        bindsDirty_ = true;
        bindParams_.resize(bindCount_);
        bindLengths_.resize(bindCount_);
        bindValues_.resize(bindCount_);
        memset(bindParams_.data(), 0, sizeof(MYSQL_BIND) * bindCount_);
    }
    else {
        MySQLStatement::rewind();
    }
}

MySQLStatement::~MySQLStatement()
{
    MySQLStatement::close();
}

void MySQLStatement::throwException()
{
    int code = static_cast<int>(mysql_stmt_errno(stmt_));
    const char* msg = mysql_stmt_error(stmt_);

    if (!msg || msg[0] == '\0') {
        code = static_cast<int>(mysql_errno(db_->getDB()));
        msg = mysql_error(db_->getDB());
    }

        throw  msg;
}

void MySQLStatement::throwIfBindsDirty()
{
    if (bindsDirty_) {
        throw "Number of binded parameters are not matching the expected";
    }
}

void MySQLStatement::bind(enum_field_types type, void* buff, bool is_unsigned, unsigned long length)
{

    if (binded_ >= bindCount_) {
        throw "MySQL bind buffer overflow";
    }

    bindsDirty_ = true;

    MYSQL_BIND& bind = bindParams_[binded_];
    bind.buffer_type = type;

    if (type != MYSQL_TYPE_NULL) {
        bind.buffer = (void*)buff;
        bind.is_null = nullptr;
        bind.is_unsigned = is_unsigned ? 1 : 0;

        if (length > 0) {
            bindLengths_[binded_] = length;
            bind.length = &bindLengths_[binded_];
        }
        else {
            bind.length = nullptr;
        }
    }

    ++binded_;

    if (binded_ >= bindCount_) {
        rewind();
    }
}

MySQLStatement & MySQLStatement::operator <<(const int32_t &n)
{
    int32_t& val = bindValues_[binded_].u.i32;
    val = n;
    bind(MYSQL_TYPE_LONG, (void*)&val, 0);
    return *this;
}

MySQLStatement & MySQLStatement::operator <<(const uint32_t &n)
{
    uint32_t& val = bindValues_[binded_].u.ui32;
    val = n;
    bind(MYSQL_TYPE_LONG, (void*)&val, 1);
    return *this;
}

MySQLStatement & MySQLStatement::operator <<(const int64_t &n)
{
    int64_t& val = bindValues_[binded_].u.i64;
    val = n;
    bind(MYSQL_TYPE_LONGLONG, (void*)&val, 0);
    return *this;
}

MySQLStatement & MySQLStatement::operator <<(const uint64_t &n)
{
    uint64_t& val = bindValues_[binded_].u.ui64;
    val = n;
    bind(MYSQL_TYPE_LONGLONG, (void*)&val, 1);
    return *this;
}

MySQLStatement & MySQLStatement::operator <<(const char *c)
{
    std::string& val = bindValues_[binded_].str;
    //WARNING_ASSERT(false, "Please use std::string operator, because '\0' could be in data");
    val = c;
    trimRightSpaces(val);
    bind(MYSQL_TYPE_STRING, (void*)val.c_str(), 0, static_cast<unsigned long>(val.length()));
    return *this;
}

MySQLStatement & MySQLStatement::operator <<(const std::string &s)
{
    std::string& val = bindValues_[binded_].str;
    val = s;
    trimRightSpaces(val);
    bind(MYSQL_TYPE_STRING, (void*)val.c_str(), 0, static_cast<unsigned long>(val.length()));
    return *this;
}

MySQLStatement & MySQLStatement::operator <<(std::nullptr_t /*n*/)
{
    bind(MYSQL_TYPE_NULL, nullptr, 0);
    return *this;
}

MySQLStatement & MySQLStatement::operator <<(const bool n)
{

    char& val = bindValues_[binded_].u.b;
    val = n ? 1 : 0;
    bind(MYSQL_TYPE_TINY, (void*)&val, 0);
    return *this;
}

std::string MySQLStatement::fetchColumn()
{
    throwIfBindsDirty();

    unsigned long& rLen = realLengths_[outPos_];

    if (fetchBuffer_.size() < rLen + 1) {
        fetchBuffer_.resize(rLen + 1);
    }

    resultSet_[outPos_].buffer = fetchBuffer_.data();
    resultSet_[outPos_].buffer_length = rLen;
    resultSet_[outPos_].is_null = &lastIsNull_;


    if (mysql_stmt_fetch_column(stmt_, &resultSet_[outPos_], outPos_, 0)) {
        throwException();
    }

    fetchBuffer_[rLen] = '\0';
    return { fetchBuffer_.data(), rLen };
}

void MySQLStatement::fetchNextRow()
{
    if (++outPos_ >= resultSetColCount_) {
        lastFetchResult_ = mysql_stmt_fetch(stmt_);
        if (lastFetchResult_ == MYSQL_NO_DATA && hasMoreResultSets()) {
            fetchNextResultSet();
        }
        outPos_ = 0;
    }
}

void MySQLStatement::fetchNextResultSet()
{
    resultSetColCount_ = 0;
    resultSet_.clear();
    realLengths_.clear();

    if (mysql_stmt_field_count(stmt_) > 0) {

        tdMysqlResUPtr res(mysql_stmt_result_metadata(stmt_), &mysql_free_result);

        if (res.get() != nullptr) {
            resultSetColCount_ = mysql_num_fields(res.get());

            if (resultSetColCount_ != 0) {

                if (resultSet_.size() < resultSetColCount_) {
                    resultSet_.resize(resultSetColCount_);
                    realLengths_.resize(resultSetColCount_);
                }

                memset(resultSet_.data(), 0, sizeof(MYSQL_BIND) * resultSet_.size());

                for (unsigned int i = 0; i < resultSetColCount_; i++) {
                    resultSet_[i].buffer_type = MYSQL_TYPE_STRING;
                    resultSet_[i].length = &realLengths_[i];
                }

                if (mysql_stmt_bind_result(stmt_, resultSet_.data())) {
                    throwException();
                }
            }
        }

        if (res.get() != nullptr && resultSetColCount_ > 0) {
            if (!useCursor_ && mysql_stmt_store_result(stmt_)) {
                throwException();
            }
            lastFetchResult_ = mysql_stmt_fetch(stmt_);
        }
    }
}

bool MySQLStatement::queryForCursor(const char* sqlQuery)
{
    constexpr auto&& select = "SELECT";
    return strncasecmp(sqlQuery, select, sizeof(select) - 1) == 0;
}

void MySQLStatement::trimRightSpaces(std::string& s)
{
    if (s.empty()) return;

    auto it = std::find_if(s.crbegin(), s.crend(), [](auto c) { return c != ' '; });
    s.resize(s.size() - std::distance(s.crbegin(), it));
}

void MySQLStatement::skipRemainingResultSets()
{
    while (hasMoreResultSets()) {};
}

MySQLStatement & MySQLStatement::operator >> (int32_t &n)
{
    std::string col = fetchColumn();
    if (!lastIsNull_) {
        try {
            n = static_cast<int32_t>(std::stoi(col));
        }
        catch (const std::exception& e) {
            throw  e.what();
        }
    }
    else {
        n = 0;
    }

    fetchNextRow();
    return *this;
}

MySQLStatement & MySQLStatement::operator >> (uint32_t &n)
{
    std::string col = fetchColumn();
    if (!lastIsNull_) {
        try {
            n = static_cast<uint32_t>(std::stoi(col));
        }
        catch (const std::exception& e) {
            throw  e.what();
        }
    }
    else {
        n = 0;
    }

    fetchNextRow();
    return *this;
}

MySQLStatement & MySQLStatement::operator >> (int64_t &n)
{
    std::string col = fetchColumn();
    if (!lastIsNull_) {
        try {
            n = static_cast<int64_t>(std::stoll(col));
        }
        catch (const std::exception& e) {
            throw e.what();
        }
    }
    else {
        n = 0;
    }

    fetchNextRow();
    return *this;
}

MySQLStatement & MySQLStatement::operator >> (uint64_t &n)
{
    std::string col = fetchColumn();
    if (!lastIsNull_) {
        try {
            n = static_cast<uint64_t>(std::stoll(col));
        }
        catch (const std::exception& e) {
            throw  e.what();
        }
    }
    else {
        n = 0;
    }

    fetchNextRow();
    return *this;
}

MySQLStatement & MySQLStatement::operator >> (float &n)
{
    std::string col = fetchColumn();
    if (!lastIsNull_) {
        try {
            n = std::stof(col);
        }
        catch (const std::exception& e) {
            throw  e.what();
        }
    }
    else {
        n = 0;
    }

    fetchNextRow();
    return *this;
}

MySQLStatement & MySQLStatement::operator >> (bool &n)
{
    std::string col = fetchColumn();
    if (!lastIsNull_) {
        n = col == "1";
    }
    else {
        n = false;
    }
    fetchNextRow();
    return *this;
}

MySQLStatement & MySQLStatement::operator >> (std::string &s)
{
    s = fetchColumn();
    if (lastIsNull_) s = "";
    fetchNextRow();
    return *this;
}

bool MySQLStatement::eof()
{
    throwIfBindsDirty();

    bool isEof = (lastFetchResult_ == MYSQL_NO_DATA);
    if (isEof) {
        skipRemainingResultSets();
    }
    return isEof;
}

void MySQLStatement::rewind()
{
    binded_ = 0;

    if (bindCount_ > 0) {
        if (mysql_stmt_bind_param(stmt_, bindParams_.data())) {
            throwException();
        }
        bindsDirty_ = false;
    }

    if (mysql_stmt_execute(stmt_)) {
        throwException();
    }

    fetchNextResultSet();
}

bool MySQLStatement::is_null()
{
    throwIfBindsDirty();
    return lastIsNull_ > 0;
}

int MySQLStatement::getRpc()
{
    throwIfBindsDirty();
    return static_cast<int>(mysql_stmt_affected_rows(stmt_));
}

void MySQLStatement::close()
{
    if (stmt_ != nullptr) {
        mysql_stmt_close(stmt_);
        stmt_ = nullptr;
    }
}

bool MySQLStatement::hasMoreResultSets()
{
    int status = mysql_stmt_next_result(stmt_);
    if (status > 0) {
        throwException();
    }

    return status == 0;
}

/* MySQLTransaction*/

MySQLTransaction::~MySQLTransaction()
{
    try {
        MySQLTransaction::rollback();
    }
    catch (const std::exception& e) {
        throw " Database Exception: %s (code %i)\n";
    }
}

void MySQLTransaction::commit()
{
    if (db_ == nullptr) return;
    if (!isOpen_) return;

    if (mysql_commit(db_->getDB())) {
        db_->throwException();
    }

    db_->haveOpenedTransaction_ = false;
    isOpen_ = false;
}

void MySQLTransaction::rollback()
{
    if (db_ == nullptr) return;
    if (!isOpen_) return;

    if (mysql_rollback(db_->getDB())) {
        db_->throwException();
    }

    db_->haveOpenedTransaction_ = false;
    isOpen_ = false;
}

/* MySQLDatabase*/

MySQLDatabase::MySQLDatabase()
{
    haveOpenedTransaction_ = false;
}

MySQLDatabase::~MySQLDatabase()
{
    MySQLDatabase::closeDatabase();
}

void MySQLDatabase::init()
{
    host_ = "localhost";
    port_ = 3306;
    dbName_ = "ashahowa";
    login_ = "root";
    pwd_ = "JzxU8d3s";
    timeout_ = static_cast<unsigned int>(1000);
    connect();
}

void MySQLDatabase::connect()
{
    if (isConnected_) return;

    mysql_init(&mysql_);

    mysql_options(&mysql_, MYSQL_PLUGIN_DIR, (void*)".");

    enum mysql_protocol_type protocol = MYSQL_PROTOCOL_TCP;
    mysql_options(&mysql_, MYSQL_OPT_PROTOCOL, &protocol);

    bool reconnect = false;
    mysql_options(&mysql_, MYSQL_OPT_RECONNECT, &reconnect);

    mysql_options(&mysql_, MYSQL_SET_CHARSET_NAME, (void*)"utf8");

    mysql_options(&mysql_, MYSQL_OPT_CONNECT_TIMEOUT, (void *)&timeout_);

    mysql_options(&mysql_, MYSQL_OPT_LOCAL_INFILE, (void*)"1");

    if (!mysql_real_connect(&mysql_, host_.c_str(), login_.c_str(), pwd_.c_str(), dbName_.c_str(), port_, nullptr, CLIENT_REMEMBER_OPTIONS | CLIENT_LOCAL_FILES | CLIENT_MULTI_STATEMENTS)) {
        int code = static_cast<int>(mysql_errno(&mysql_));
        throw mysql_error(&mysql_);
    }

    isConnected_ = true; // here tcp connection is already established

    execDML("SET NAMES utf8 COLLATE utf8_bin;");

    freeResult();
}

std::unique_ptr<MySQLTransaction> MySQLDatabase::createTransaction()
{
        return std::unique_ptr<MySQLTransaction>(new MySQLTransaction());
}

void MySQLDatabase::closeDatabase()
{
    if (!isConnected_) return;

    mysql_close(&mysql_);
    isConnected_ = false;
}

int MySQLDatabase::execScalar(const char* sql)
{
    if (mysql_real_query(&mysql_, sql, static_cast<unsigned long>(strlen(sql)))) {
        throwException();
    }

    tdMysqlResUPtr result(mysql_store_result(&mysql_), &mysql_free_result);
    if (result.get() == nullptr) {
        throwException();
    }

    my_ulonglong rowsCount = mysql_num_rows(result.get());
    unsigned int fieldCount = mysql_num_fields(result.get());

    if (rowsCount != 1 && fieldCount != 1) {
        throw  "Invalid scalar query";
    }

    MYSQL_ROW row = mysql_fetch_row(result.get());
    if (row == 0) {
        throw  "Invalid scalar query";
    }
    if (row[0] == nullptr) {
        return 0;
    }

    try {
        return std::stoi(row[0]);
    }
    catch (const std::exception& e) {
        throw e.what();
    }
}

void MySQLDatabase::throwException()
{
    int code = static_cast<int>(mysql_errno(&mysql_));
    std::string msg = mysql_error(&mysql_);

        throw  msg.c_str();
}

void MySQLDatabase::freeResult()
{
    MYSQL_RES* res = mysql_store_result(&mysql_);
    mysql_free_result(res);
}

bool MySQLDatabase::haveOpenTransaction() const
{
    return haveOpenedTransaction_;
}

int MySQLDatabase::execDML(const char* sql)
{

    if (mysql_real_query(&mysql_, sql, static_cast<unsigned long>(strlen(sql)))) {
        throwException();
    }

    my_ulonglong arows = 0;
    do {
        tdMysqlResUPtr result(mysql_store_result(&mysql_), &mysql_free_result);
        if (result.get()) {
        }
        else  /* no result set or error */
        {
            if (mysql_field_count(&mysql_) != 0) {
                throwException();
            }

            my_ulonglong newRows = mysql_affected_rows(&mysql_);
            if (newRows == static_cast<my_ulonglong>(-1)) {
                throwException();
            }
            arows += newRows;
        }
        /* more results? -1 = no, >0 = error, 0 = yes (keep looping) */
    } while (mysql_next_result(&mysql_) == 0);

    return static_cast<int>(arows);
}

std::unique_ptr<MySQLStatement> MySQLDatabase::compileStatement(const char* sql, int bufferRows)
{
    return std::make_unique<MySQLStatement>(*this, sql, static_cast<uint32_t>(bufferRows));
}
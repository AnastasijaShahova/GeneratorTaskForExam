#ifndef UNTITLED5_MYSQLDATABASE_H
#define UNTITLED5_MYSQLDATABASE_H

#include <mysql.h>
#include <string>
#include <memory>
#include <vector>
#include <mutex>
#include <unordered_map>

using namespace std::literals::chrono_literals;
class MySQLDatabase;

class MySQLStatement {
public:
    MySQLStatement(MySQLDatabase &db, const char *sql, const uint32_t prefetchRows);
    ~MySQLStatement();

    MySQLStatement &operator <<(const int32_t &n) ;
    MySQLStatement &operator <<(const uint32_t &n) ;
    MySQLStatement &operator <<(const int64_t &n) ;
    MySQLStatement &operator <<(const uint64_t &n) ;
    MySQLStatement &operator <<(const char *c) ;
    MySQLStatement &operator <<(const std::string &s) ;
    MySQLStatement &operator <<(std::nullptr_t /*n*/) ;
    MySQLStatement &operator <<(const bool n) ;

    MySQLStatement &operator >> (int32_t &n) ;
    MySQLStatement &operator >> (uint32_t &n) ;
    MySQLStatement &operator >> (int64_t &n) ;
    MySQLStatement &operator >> (uint64_t &n) ;
    MySQLStatement &operator >> (float &n) ;
    MySQLStatement &operator >> (bool &n) ;
    MySQLStatement &operator >> (std::string &s) ;

    bool eof() ;
    void rewind() ;
    bool is_null() ;
    int getRpc() ;
    void close() ;
    bool hasMoreResultSets();

private:
    struct BindValue {
        std::string str;
        union {
            int32_t i32;
            uint32_t ui32;
            int64_t i64;
            uint64_t ui64;
            char b;
        } u;
    };

    void throwException();
    void throwIfBindsDirty();
    void bind(enum_field_types type, void* buff, bool is_unsigned, unsigned long length = 0);
    std::string fetchColumn();
    void fetchNextRow();
    void fetchNextResultSet();
    bool queryForCursor(const char* sqlQuery);
    void trimRightSpaces(std::string& s);
    void skipRemainingResultSets();

    MySQLDatabase* db_ = nullptr;
    MYSQL_STMT* stmt_ = nullptr;
    bool bindsDirty_ = false;
    unsigned long bindCount_ = 0;
    bool lastIsNull_ = 0;
    unsigned long binded_ = 0;
    std::vector<MYSQL_BIND> bindParams_;
    std::vector<unsigned long> bindLengths_;
    std::vector<BindValue> bindValues_;
    int lastFetchResult_ = MYSQL_NO_DATA;
    unsigned int resultSetColCount_ = 0;
    unsigned long outPos_ = 0;
    std::vector<MYSQL_BIND> resultSet_;
    std::vector<unsigned long> realLengths_;
    std::vector<char> fetchBuffer_;
    bool useCursor_ = false;
};

class MySQLTransaction {
public:
    MySQLTransaction(){};
    ~MySQLTransaction();
    void commit() ;
    void rollback() ;

private:
    MySQLDatabase* db_ = nullptr;
    bool isOpen_ = false;
};

class MySQLDatabase {
public:
    MySQLDatabase();
    ~MySQLDatabase() ;

    void init(const std::string &host, const std::string &user, const std::string &password, const std::string &dbName, int port);
    std::unique_ptr<MySQLTransaction> createTransaction();
    bool haveOpenTransaction() const;
    void closeDatabase() ;
    int execScalar(const char* sql) ;
    int execDML(const char* sql) ;
    std::unique_ptr<MySQLStatement> compileStatement(const char* sql, int bufferRows) ;
    std::string getBindName(unsigned bindNum, const std::string &bindType, const std::string &funcStr) const ;

    MYSQL* getDB() { return &mysql_; }
    void throwException();

    void freeResult();
private:
    void connect();

    bool isConnected_ = false;
    std::string host_;
    int port_;
    std::string dbName_;
    std::string login_;
    std::string pwd_;
    unsigned int timeout_;
    bool haveOpenedTransaction_;

    MYSQL mysql_;

    friend class MySQLTransaction;
};

typedef std::unique_ptr<MYSQL_RES, decltype(mysql_free_result)*> tdMysqlResUPtr;

#endif
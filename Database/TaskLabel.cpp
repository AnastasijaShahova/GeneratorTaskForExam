#include "TaskLabel.h"


void TaskLabel::getTextLabelFromDb(int id)
{
    MySQLDatabase db;
    db.init();
    txtLabel.id = id;
    const std::string query = "select label,number_task from task_label where id=" + std::to_string(id) + ";";
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str() , 200);
    if (!ptr->eof()) {
        (*ptr)>>txtLabel.textLabel_;
        (*ptr)>>txtLabel.numberTask;
    }
}

void TaskLabel::getVector(std::vector<textLabel>& txtLbl)
{
    for(int i = 1 ; i <= getCountLineQuery(); ++i) {
        getTextLabelFromDb(i);
        txtLbl.push_back(txtLabel);
    }
}

int TaskLabel::getCountLineQuery()
{
    int count = 0;
    MySQLDatabase db;
    db.init();
    const std::string query = "select count(*) from task_label;";
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str() , 200);
    if (!ptr->eof()) {
        (*ptr)>>count;
    }
    return count;
}

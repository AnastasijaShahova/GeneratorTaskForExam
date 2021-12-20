#ifndef UNTITLED5_TASKLABEL_H
#define UNTITLED5_TASKLABEL_H

#include <string>
#include <vector>
#include "MySqlDatabase.h"

struct textLabel {
    int id;
    std::string textLabel_;
    int numberTask;
//    textLabel(int id_, std::string txt, int number):
//    id(std::move(id_)), textLabel_(std::move(txt)), numberTask(std::move(number)){}
};

class TaskLabel {
public:
    TaskLabel(){}
    void getTextLabelFromDb(int id);
    void getVector(std::vector<textLabel>& txtLbl);
    int getCountLineQuery();

private:
    textLabel txtLabel;
};

#endif //UNTITLED5_TASKLABEL_H

#include <iostream>
#include "ConnectionMysql.h"
#include "Task11.h"

int main() {
    const std::string host = "localhost";
    const std::string user = "root";
    const std::string password = "JzxU8d3s";
    const std::string dbName = "ashahowa";
    int port = 3306;

        const std::string& str = "Ответ дайте в битах";
        //генерируется номер(id),потом передается в контруктор,а потом определяется тип
        int r = rand() % 3;

        //генерируется рандомное число,потом по этому числу определяется тип задания
        Task11 task(1);
        task.solutionTask(type1, str);
//        task.putTableAnswer();


    return 0;
}

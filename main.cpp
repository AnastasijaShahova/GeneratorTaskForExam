#include <iostream>
#include "Tasks/Task11.h"
#include "Tasks/Task7.h"

int main() {

        //генерируется номер(id)
        int r = rand() % 4;

        //генерируется рандомное число,потом по этому числу определяется тип задания
//        Task11 task(4);
//        task.solutionTask(type2);

        Task7 task7(6);
        task7.solutionTask(type2);

    return 0;
}

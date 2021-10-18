#include <iostream>
#include "Task11.h"

int main() {

        //генерируется номер(id),потом передается в контруктор,а потом определяется тип
        int r = rand() % 3;

        //генерируется рандомное число,потом по этому числу определяется тип задания
        Task11 task(5);
        task.solutionTask(type4);

    return 0;
}

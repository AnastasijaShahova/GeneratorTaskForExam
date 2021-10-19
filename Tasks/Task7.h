#ifndef UNTITLED5_TASK7_H
#define UNTITLED5_TASK7_H

#include "../Database/DataTask.h"

class Task7 {
public:



private:
    std::vector<int> number_;
    std::unique_ptr<DataTask> table = std::make_unique<DataTask>();
};


#endif //UNTITLED5_TASK7_H

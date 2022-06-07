#ifndef UNTITLED5_TASKRESOURCEFACTORY_H
#define UNTITLED5_TASKRESOURCEFACTORY_H

#include "IResourceFactory.h"
#include "../json.hpp"
#include "../Tasks/ITask.h"
#include "../Tasks/Task11.h"
#include "../Tasks/Task1.h"
#include "../Tasks/Task7.h"
#include "../Tasks/TaskFactory.h"

#define TaskNumber11 11
#define TaskNumber1 1
#define TaskNumber7 7
#define TaskNumber8 8
#define TaskNumber14 14
#define TaskNumber6 6

class TaskResourceFactory : public IResourceFactory {
public:
    TaskResourceFactory();
    std::shared_ptr<Resource> get_resource() const override;
    void getTask(int number);

private:
    int get_query_param(const std::shared_ptr<Session> session) const;
    std::string to_json();
    void get_handler(const std::shared_ptr<Session> session);
    std::shared_ptr<Resource> resource_;
    std::unique_ptr<TaskFactory> taskFactory;
};


#endif //UNTITLED5_TASKRESOURCEFACTORY_H

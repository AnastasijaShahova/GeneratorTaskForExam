#ifndef UNTITLED5_TASKSERVICE_H
#define UNTITLED5_TASKSERVICE_H

#include "IService.h"
#include "IResourceFactory.h"
#include "IServiceSetting.h"

enum class As {
    Login,
    Label,
    Task,
    AllStat,
    PersonalStat,
    DoneExam,
    TeachersList
};

class TaskService : public IService{
public:
    TaskService(std::shared_ptr<IServiceSettings> settings_factory);
    void start() override;
private:
    IResourceFactory* makeRes(As type);
    Service service_;
    std::shared_ptr<IServiceSettings> settings_factory_;

};


#endif //UNTITLED5_TASKSERVICE_H

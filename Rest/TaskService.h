#ifndef UNTITLED5_TASKSERVICE_H
#define UNTITLED5_TASKSERVICE_H

#include "IService.h"
#include "IResourceFactory.h"
#include "IServiceSetting.h"

class TaskService : public IService{
public:
    TaskService(
            std::shared_ptr<IResourceFactory> resource_factory,
            std::shared_ptr<IServiceSettings> settings_factory);
    void start() final;
private:
    Service service_;
    std::shared_ptr<IServiceSettings> settings_factory_;
};


#endif //UNTITLED5_TASKSERVICE_H

#include "TaskService.h"

TaskService::TaskService(
        std::shared_ptr<IResourceFactory> resource_factory,
        std::shared_ptr<IServiceSettings> settings_factory)
{
    settings_factory = settings_factory;
    service.publish(resource_factory->get_resource());
}

void TaskService::start()
{
    service.start(settings_factory->get_settings());
}
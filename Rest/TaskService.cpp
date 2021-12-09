#include "TaskService.h"

TaskService::TaskService( std::shared_ptr<IResourceFactory> resource_factory, std::shared_ptr<IServiceSettings> settings_factory)
{
    settings_factory_ = settings_factory;
    service_.publish(resource_factory->get_resource());
}

void TaskService::start()
{
    service_.start(settings_factory_->get_settings());
}
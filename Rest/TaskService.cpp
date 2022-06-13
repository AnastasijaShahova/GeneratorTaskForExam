#include "TaskService.h"
#include "LoginResourceFactory.h"
#include "ServiceSettingFactory.h"
#include "TaskLabelResourceFactory.h"
#include "TaskResourceFactory.h"
#include "StudentsAllStatistics.h"
#include "PersonalStatistics.h"

TaskService::TaskService(std::shared_ptr<IServiceSettings> settings_factory)
{
    settings_factory_ = settings_factory;
    service_.publish(makeRes(As::Login)->get_resource());
    service_.publish(makeRes(As::Label)->get_resource());
    service_.publish(makeRes(As::Task)->get_resource());
}

IResourceFactory* TaskService::makeRes(As type) {
    IResourceFactory* res;
    switch (type){
        case As::Login:
        {
            res = new LoginResourceFactory();
            break;
        }
        case As::Label: {
            res = new TaskLabelResourceFactory();
            break;
        }
        case As::Task: {
            res = new TaskResourceFactory();
            break;
        }
        case As::AllStat: {
            res = new StudentsAllStatistics();
            break;
        }
        case As::PersonalStat: {
            res = new PersonalStatistics();
            break;
        }
    }
    return res;
}

void TaskService::start()
{
    service_.start(settings_factory_->get_settings());
}

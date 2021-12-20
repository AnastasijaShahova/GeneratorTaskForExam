#include "ResourceFactoryClass.h"
#include "LoginResourceFactory.h"
#include "TaskLabelResourceFactory.h"
#include "TaskResourceFactory.h"

ResourceFactoryClass::ResourceFactoryClass()
{
    resource_ = std::make_shared<Resource>();
    resource_->set_path( "/auth/login");

}

int ResourceFactoryClass::get_query_param(const std::shared_ptr<Session> session) const
{
    const auto& request = session->get_request();
    std::string param = request->get_query_parameter("pages");
    return std::stoi(param);
}

std::shared_ptr<IResourceFactory> ResourceFactoryClass::chooseRecource(int param)
{
    switch(param) {
        case 1: {
            return std::make_shared<LoginResourceFactory>();
            break;
        }
        case 2: {
            return std::make_shared<TaskLabelResourceFactory>();
            break;
        }
        case 3: {
            return std::make_shared<TaskResourceFactory>();
            break;
        }
        default:
            break;
    }
}
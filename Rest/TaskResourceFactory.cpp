#include "TaskResourceFactory.h"
#include <sstream>
#include "../json.hpp"

TaskResourceFactory::TaskResourceFactory()
{
    userAuth = std::make_unique<LogIn>();
    resource_ = std::make_shared<Resource>();
    resource_->set_path( "/auth/login");
    resource_->set_method_handler("GET",
                                  [&](const auto session) {
        get_handler(session);
    });
}

std::shared_ptr<Resource> TaskResourceFactory::get_resource() const
{
    return resource_;
}

std::tuple<std::string, std::string> TaskResourceFactory::get_path_parameters(const std::shared_ptr<Session> session) const
{
    const auto& request = session->get_request();
    const auto login = request->get_path_parameter("login").c_str();
    const auto password = request->get_path_parameter("password").c_str();
    return std::make_tuple(login, password);
}

std::string TaskResourceFactory::to_json(std::unique_ptr<LogIn> userData)
{
    nlohmann::json jsonResult = {
            {"userData",  userData->getUsersData().name},
            {"password",  userData->getUsersData().password },
            {"status", userData->getUsersData().loginSuccesfull},
            {"message",   userData->getUsersData().message}
    };
    return jsonResult.dump();
}

void TaskResourceFactory::get_handler(const std::shared_ptr<Session> session)
{
    const auto [login, password] = get_path_parameters(session);
    userAuth->setUsersData(login, password);
    userAuth->checkLogin();
    auto content = to_json(std::move(userAuth));
    session->close(OK, content,
                   {{"Content-Length", std::to_string(content.size())}});
}
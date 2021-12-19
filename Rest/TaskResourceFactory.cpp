#include "TaskResourceFactory.h"
#include <sstream>

TaskResourceFactory::TaskResourceFactory()
{
    resource_ = std::make_shared<Resource>();
    resource_->set_path( "/auth/login");
    resource_->set_method_handler("POST",
                                 [this](const std::shared_ptr<restbed::Session> session) {
        this->post_handler(session);
    });
}

std::shared_ptr<Resource> TaskResourceFactory::get_resource() const
{
    return resource_;
}

std::string TaskResourceFactory::to_json(LogIn userData)
{
nlohmann::json jsonResult = nlohmann::json{{"email", userData.getUsersData().name},
                                           {"status", userData.getUsersData().loginSuccesfull},
                                           {"password", userData.getUsersData().password},
                                           {"message", userData.getUsersData().message}};
    return jsonResult.dump();
}

std::tuple<std::string, std::string> TaskResourceFactory::from_json(const Bytes& body)
{
    nlohmann::json j = nlohmann::json::parse(body);
    std::string email, password ;
    j.at("email").get_to(email);
    j.at("password").get_to(password);
    return std::make_tuple(email, password);
}

//void TaskResourceFactory::get_handler(const std::shared_ptr<Session> session)
//{
//    const auto [login, password] = get_path_parameters(session);
//    userAuth.setUsersData(login, password);
//    userAuth.checkLogin();
//    auto content = to_json(userAuth);
//    session->close(OK, content,
//                   {{"Content-Length", std::to_string(content.size())}});
//}

void TaskResourceFactory::post_handler(const std::shared_ptr<restbed::Session> session)
{

    const auto request = session->get_request();
    long content_length = request->get_header("Content-Length", 0);
    session->fetch(content_length,
                   [request, this](const std::shared_ptr<restbed::Session> session, const Bytes& body)
        {
        LogIn log(from_json(body));
        log.checkLogin();
        auto content = to_json(log);
        session->close(restbed::OK, content, { { "Content-Length",  std::to_string(content.size())}});
        });
}
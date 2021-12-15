#include "TaskResourceFactory.h"
#include <sstream>

TaskResourceFactory::TaskResourceFactory()
{
    resource_ = std::make_shared<Resource>();
    resource_->set_path( "/auth/login");
//    resource_->set_method_handler("GET",
//                                  [&](const auto session) {
//        get_handler(session);
//    });
    resource_->set_method_handler("POST",
                                 [this](const std::shared_ptr<restbed::Session> session) {
        this->post_handler(session);
    });
}

std::shared_ptr<Resource> TaskResourceFactory::get_resource() const
{
    return resource_;
}

//std::tuple<std::string, std::string> TaskResourceFactory::get_path_parameters(const std::shared_ptr<Session> session) const
//{
//    //надо получать из json
//    const auto& request = session->get_request();
//
//
//    auto t = request->get_body();
//    const auto login = request->get_path_parameter("/auth/login").c_str();
//    const auto password = request->get_path_parameter("/auth/login").c_str();
//    return std::make_tuple(login, password);
//}

std::string TaskResourceFactory::to_json(LogIn userData)
{
    nlohmann::json jsonResult = {
            {"email",  userData.getUsersData().name},
            {"password",  userData.getUsersData().password },
            {"status", userData.getUsersData().loginSuccesfull},
            {"message",   userData.getUsersData().message}
    };
    return jsonResult.dump();
}

//std::tuple<std::string, std::string> TaskResourceFactory::from_json(nlohmann::json jsonObj)
//{
//
//    std::string login = jsonObj["email"].get<std::string>();
//    std::string password = jsonObj["password"].get<std::string>();
//}

std::tuple<std::string, std::string> TaskResourceFactory::from_json(nlohmann::json jsonObj)
{
    std::string email, password ;

    jsonObj.at({"email"}).get_to(email);
    jsonObj.at({"password"}).get_to(password);
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
                   [request,this](const std::shared_ptr< restbed::Session > session, const restbed::Bytes& body)
        {
        LogIn log(from_json(body));
        log.checkLogin();
        auto content = to_json(log);
        session->close(restbed::OK, content,{ { "Content-Length",  std::to_string(content.size())}});
        });
}
#ifndef UNTITLED5_LOGINRESOURCEFACTORY_H
#define UNTITLED5_LOGINRESOURCEFACTORY_H
#include "IResourceFactory.h"
#include "../Database/LogIn.h"
#include "../json.hpp"


class LoginResourceFactory : public IResourceFactory{
public:
    LoginResourceFactory();
    std::shared_ptr<Resource> get_resource() const override;
    void post_handler(const std::shared_ptr<restbed::Session> session);

private:
    std::tuple<std::string, std::string>get_path_parameters(const std::shared_ptr<Session> session) const;
    std::string to_json(LogIn userData);
    std::tuple<std::string, std::string> from_json(const Bytes& body);
    std::shared_ptr<Resource> resource_;
};


#endif //UNTITLED5_LOGINRESOURCEFACTORY_H

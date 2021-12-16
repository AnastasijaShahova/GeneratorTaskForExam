#ifndef UNTITLED5_TASKRESOURCEFACTORY_H
#define UNTITLED5_TASKRESOURCEFACTORY_H
#include "IResourceFactory.h"
#include "LogIn.h"
#include "../json.hpp"


class TaskResourceFactory : public IResourceFactory{
public:
    TaskResourceFactory();
    std::shared_ptr<Resource> get_resource() const override;
    void post_handler(const std::shared_ptr<restbed::Session> session);

private:
    std::tuple<std::string, std::string>get_path_parameters(const std::shared_ptr<Session> session) const;
    std::string to_json(LogIn userData);
    std::tuple<std::string, std::string> from_json(const Bytes& body);

    void get_handler(const std::shared_ptr<Session> session);
    std::shared_ptr<Resource> resource_;
//    LogIn userAuth;
};


#endif //UNTITLED5_TASKRESOURCEFACTORY_H

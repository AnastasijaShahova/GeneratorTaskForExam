#ifndef UNTITLED5_TASKRESOURCEFACTORY_H
#define UNTITLED5_TASKRESOURCEFACTORY_H
#include "IResourceFactory.h"
#include "LogIn.h"


class TaskResourceFactory : public IResourceFactory{
public:
    TaskResourceFactory();
    std::shared_ptr<Resource> get_resource() const override;

private:
    std::tuple<std::string, std::string>get_path_parameters(const std::shared_ptr<Session> session) const;
    std::string to_json(std::unique_ptr<LogIn> userData);
    void get_handler(const std::shared_ptr<Session> session);
    std::shared_ptr<Resource> resource_;
    std::unique_ptr<LogIn> userAuth;
};


#endif //UNTITLED5_TASKRESOURCEFACTORY_H

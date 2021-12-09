#ifndef UNTITLED5_TASKRESOURCEFACTORY_H
#define UNTITLED5_TASKRESOURCEFACTORY_H
#include "IResourceFactory.h"

class TaskResourceFactory : public IResourceFactory{
public:
    TaskResourceFactory();
    std::shared_ptr<Resource> get_resource() const override;

private:
    float foo(float num1, float num2, std::string operation);
    std::tuple<float, float, std::string>
    get_path_parameters(const std::shared_ptr<Session> session) const;
    std::string to_json(float result);
    void get_handler(const std::shared_ptr<Session> session);
    std::shared_ptr<Resource> resource_;
};


#endif //UNTITLED5_TASKRESOURCEFACTORY_H

#ifndef UNTITLED5_TASKLABELRESOURCEFACTORY_H
#define UNTITLED5_TASKLABELRESOURCEFACTORY_H
#include "IResourceFactory.h"
#include "../json.hpp"
#include "../Database/TaskLabel.h"

class TaskLabelResourceFactory : public IResourceFactory {
public:
    TaskLabelResourceFactory();
    std::shared_ptr<Resource> get_resource() const override;

private:
    std::tuple<std::string, std::string>get_path_parameters(const std::shared_ptr<Session> session) const;
    std::string to_json(std::vector<textLabel> txtLbl);

    void get_handler(const std::shared_ptr<Session> session);
    std::shared_ptr<Resource> resource_;
    TaskLabel taskLabel;
};


#endif //UNTITLED5_TASKLABELRESOURCEFACTORY_H

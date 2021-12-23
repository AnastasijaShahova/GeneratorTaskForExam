#include "TaskLabelResourceFactory.h"


TaskLabelResourceFactory::TaskLabelResourceFactory()
{
    resource_ = std::make_shared<Resource>();
    resource_->set_path( "/topics");
    resource_->set_method_handler("GET",
                                  [this](const std::shared_ptr<restbed::Session> session) {
        this->get_handler(session);
    });
}

std::shared_ptr<Resource> TaskLabelResourceFactory::get_resource() const
{
    return resource_;
}

std::string TaskLabelResourceFactory::to_json(std::vector<textLabel> txtLbl)
{
    nlohmann::json jsonResult = nlohmann::json::array();
    for ( auto it = txtLbl.begin(); it != txtLbl.end(); ++it ) {
        jsonResult.push_back({ {"id", it->id},
                                    {"text", it->textLabel_},
                                    {"number", it->numberTask}
                                  }
                             );
    }
    return jsonResult.dump();
}

void TaskLabelResourceFactory::get_handler(const std::shared_ptr<Session> session)
{
    std::vector<textLabel> txtLbl;
    taskLabel.getVector(txtLbl);
    auto content = to_json(txtLbl);
    session->close(OK, content,
                   {{"Content-Length", std::to_string(content.size())}});
}

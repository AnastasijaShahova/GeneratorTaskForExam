#include "TaskResourceFactory.h"


TaskResourceFactory::TaskResourceFactory()
{
    resource_ = std::make_shared<Resource>();
    resource_->set_path( "/questions");
    resource_->set_method_handler("GET",
                                  [this](const std::shared_ptr<restbed::Session> session) {
        this->get_handler(session);
    });
}

std::shared_ptr<Resource> TaskResourceFactory::get_resource() const
{
    return resource_;
}

std::string TaskResourceFactory::to_json()
{
    nlohmann::json jsonResult = nlohmann::json::array();
    for ( auto it = taskFactory->getTskStr().begin(); it != taskFactory->getTskStr().end() ; ++it ) {
        jsonResult.push_back({ {"answerId", it->id},
                               {"text", it->text},
                               {"number", it->number},
                               {"answer", it->answer}
        }
        );
    }
    return jsonResult.dump();
}

void TaskResourceFactory::get_handler(const std::shared_ptr<Session> session)
{
    int parametrs = get_query_param(session);
    getTask(parametrs);
    auto content = to_json();
    session->close(OK, content,
                   {{"Content-Length", std::to_string(content.size())}});
}

int TaskResourceFactory::get_query_param(const std::shared_ptr<Session> session) const
{
    const auto& request = session->get_request();
    std::string param1 = request->get_query_parameter("topicId");
    return std::stoi(param1);
}

void TaskResourceFactory::getTask(int number)
{
    taskFactory = std::make_unique<TaskFactory>();
    switch (number) {
        case TaskNumber11: {
            taskFactory->createTask(std::make_unique<Task11>(number), number);
            break;
        }
        case TaskNumber1: {
            taskFactory->createTask(std::make_unique<Task1>(10,5), number);
            break;
        }
        case TaskNumber7: {
            taskFactory->createTask(std::make_unique<Task7>(number), number);
            break;
        }
//        case TaskNumber14: {
//            taskFactory->createTask(std::make_unique<Task14>(number), number);
//            break;
//        }
//        case TaskNumber6: {
//            taskFactory->createTask(std::make_unique<Task6>(number), number);
//            break;
//        }
        default:
            break;
    }
}

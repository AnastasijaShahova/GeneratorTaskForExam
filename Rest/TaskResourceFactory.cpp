#include "TaskResourceFactory.h"
#include <sstream>
#include <iomanip>
#include "../json.hpp"

TaskResourceFactory::TaskResourceFactory()
{
    resource_ = std::make_shared<Resource>();
    resource_->set_method_handler("GET",
                                  [&](const auto session) {
        get_handler(session);
    });
}

std::shared_ptr<Resource> TaskResourceFactory::get_resource() const
{
    return resource_;
}

float TaskResourceFactory::foo(float num1, float num2, std::string operation)
{
    if(operation == "add") {
        return num1 + num2;
    }
    else if(operation == "subtract") {
        return num1 - num2;
    }
    else if(operation == "multiply") {
        return num1 * num2;
    }
    else if(operation == "divide") {
        return num1 / num2;
    }
}

std::tuple<float, float, std::string> TaskResourceFactory::get_path_parameters(
        const std::shared_ptr<Session> session) const
{
    const auto& request = session->get_request();
    const auto operation = request->get_path_parameter("operation");
    auto num1 = atof(request->get_path_parameter("num1").c_str());
    auto num2 = atof(request->get_path_parameter("num2").c_str());
    return make_tuple(num1, num2, operation);
}

std::string TaskResourceFactory::to_json(float result)
{
    std::ostringstream str_stream;
    str_stream << result;
    nlohmann::json jsonResult = {
            {"result", str_stream.str()}
    };
    return jsonResult.dump();
}

void TaskResourceFactory::get_handler(const std::shared_ptr<Session> session)
{
    const auto [num1, num2, operation] = get_path_parameters(session);
    auto result = foo(num1, num2, operation);
    auto content = to_json(result);
    session->close(OK, content,
                   {{"Content-Length", std::to_string(content.size())}});
}
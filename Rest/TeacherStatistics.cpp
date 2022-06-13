#include "TeacherStatistics.h"
#include <sstream>

TeacherStatistics::TeacherStatistics()
{
    resource_ = std::make_shared<Resource>();
    resource_->set_path( "/repsonalRatingForTeacher");
    resource_->set_method_handler("POST",
                                  [this](const std::shared_ptr<restbed::Session> session) {
        this->post_handler(session);
    });
}

std::shared_ptr<Resource> TeacherStatistics::get_resource() const
{
    return resource_;
}

std::string TeacherStatistics::to_json(std::vector<user_stat> stat)
{
    nlohmann::json jsonResult = nlohmann::json::array();
    int i = 1;
    for ( auto it = stat.begin(); it != stat.end(); ++it ) {
        jsonResult.push_back({ {"name", it->number_task},
                               {"label", it->label},
                               {"persent", it->present}
        }
        );
        ++i;
    }
    return jsonResult.dump();

}

void TeacherStatistics::post_handler(const std::shared_ptr<Session> session)
{
    const auto request = session->get_request();
    long content_length = request->get_header("Content-Length", 0);
    session->fetch(content_length,
                   [request, this](const std::shared_ptr<restbed::Session> session, const Bytes& body)
                   {
        std::string name(from_json(body));
        Statistics dataStatistic(name);
        dataStatistic.countPersentIncorrect();
        std::vector<user_stat> usr_stat = dataStatistic.getStatTask();
        auto content = to_json(usr_stat);
        session->close(restbed::OK, content, { { "Content-Length",  std::to_string(content.size())}});
                   });
}

std::string TeacherStatistics::from_json(const Bytes& body)
{
    nlohmann::json j = nlohmann::json::parse(body);
    std::string name;
    j.at("name").get_to(name);
    return name;
}


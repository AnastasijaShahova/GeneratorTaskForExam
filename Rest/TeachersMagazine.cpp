#include "TeachersMagazine.h"
#include <sstream>

TeachersMagazine::TeachersMagazine()
{
    resource_ = std::make_shared<Resource>();
    resource_->set_path( "/teacherRaiting");
    resource_->set_method_handler("GET",
                                  [this](const std::shared_ptr<restbed::Session> session) {
        this->get_handler(session);
    });
}

std::shared_ptr<Resource> TeachersMagazine::get_resource() const
{
    return resource_;
}

std::string TeachersMagazine::to_json( std::vector<for_teacher> teach)
{
    nlohmann::json jsonResult = nlohmann::json::array();
    int i = 1;
    for ( auto it = teach.begin(); it != teach.end(); ++it ) {
        jsonResult.push_back({ {"name", it->name},
                               {"email", it->email},
                               {"color", it->color}
        }
        );
        ++i;
    }
    return jsonResult.dump();

}

void TeachersMagazine::get_handler(const std::shared_ptr<Session> session)
{
    std::vector<for_teacher> statistic;
    dataStatistic->countColor();
    statistic = dataStatistic->getForTeach();
    auto content = to_json(statistic);
    session->close(OK, content,
                   {{"Content-Length", std::to_string(content.size())}});
}

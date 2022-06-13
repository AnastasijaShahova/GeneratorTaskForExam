#include "StudentsAllStatistics.h"
#include <sstream>

StudentsAllStatistics::StudentsAllStatistics()
{
    resource_ = std::make_shared<Resource>();
    resource_->set_path( "/rating");
    resource_->set_method_handler("GET",
                                  [this](const std::shared_ptr<restbed::Session> session) {
        this->get_handler(session);
    });
}

std::shared_ptr<Resource> StudentsAllStatistics::get_resource() const
{
    return resource_;
}

std::string StudentsAllStatistics::to_json(std::vector<allStatistic> all)
{
    nlohmann::json jsonResult = nlohmann::json::array();
    int i = 1;
    for ( auto it = all.begin(); it != all.end(); ++it ) {
        jsonResult.push_back({ {"name", it->name},
                               {"email", it->email},
                               {"allCount", it->all_count},
                               {"persent", it->persent},
                               {"numberRating", i}
        }
        );
        ++i;
    }
    return jsonResult.dump();

}

void StudentsAllStatistics::get_handler(const std::shared_ptr<Session> session)
{
    std::vector<allStatistic> statistic;
    dataStatistic->countPersentDone();
    statistic = dataStatistic->getAll();
    auto content = to_json(statistic);
    session->close(OK, content,
                   {{"Content-Length", std::to_string(content.size())}});
}

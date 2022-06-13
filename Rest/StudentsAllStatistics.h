#ifndef UNTITLED5_STUDENTSALLSTATISTICS_H
#define UNTITLED5_STUDENTSALLSTATISTICS_H

#include "IResourceFactory.h"
#include "../Database/Statistics.h"
#include "../json.hpp"

class StudentsAllStatistics : public IResourceFactory{
public:
    StudentsAllStatistics();
    std::shared_ptr<Resource> get_resource() const override;

private:
    std::tuple<std::string, std::string>get_path_parameters(const std::shared_ptr<Session> session) const;
    std::string to_json(std::vector<allStatistic> all);

    void get_handler(const std::shared_ptr<Session> session);
    std::shared_ptr<Resource> resource_;
    std::unique_ptr<Statistics> dataStatistic;
};

#endif //UNTITLED5_STUDENTSALLSTATISTICS_H

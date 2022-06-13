#ifndef UNTITLED5_TEACHERSMAGAZINE_H
#define UNTITLED5_TEACHERSMAGAZINE_H

#include "IResourceFactory.h"
#include "../Database/Statistics.h"
#include "../json.hpp"

class TeachersMagazine : public IResourceFactory {
public:
    TeachersMagazine();
    std::shared_ptr<Resource> get_resource() const override;

private:
    std::tuple<std::string, std::string>get_path_parameters(const std::shared_ptr<Session> session) const;
    std::string to_json(std::vector<for_teacher> teach);

    void get_handler(const std::shared_ptr<Session> session);
    std::shared_ptr<Resource> resource_;
    std::unique_ptr<Statistics> dataStatistic;
};


#endif //UNTITLED5_TEACHERSMAGAZINE_H

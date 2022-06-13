#ifndef UNTITLED5_TEACHERSTATISTICS_H
#define UNTITLED5_TEACHERSTATISTICS_H
#include "IResourceFactory.h"
#include "../Database/LogIn.h"
#include "../json.hpp"
#include "../Database/Statistics.h"

class TeacherStatistics : public IResourceFactory {
public:
    TeacherStatistics();
    std::shared_ptr<Resource> get_resource() const override;

private:
    std::tuple<std::string, std::string>get_path_parameters(const std::shared_ptr<Session> session) const;
    std::string to_json(std::vector<user_stat> stat);
    std::string from_json(const Bytes& body);

    void post_handler(const std::shared_ptr<Session> session);
    std::shared_ptr<Resource> resource_;

};

#endif //UNTITLED5_TEACHERSTATISTICS_H

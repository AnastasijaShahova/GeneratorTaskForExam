#ifndef UNTITLED5_ISERVICESETTING_H
#define UNTITLED5_ISERVICESETTING_H

#include <memory>
#include <restbed>

using namespace restbed;

class IServiceSettings {
public:
    virtual std::shared_ptr<Settings> get_settings() const = 0;
};

#endif //UNTITLED5_ISERVICESETTING_H

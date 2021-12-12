#ifndef UNTITLED5_SERVICESETTINGFACTORY_H
#define UNTITLED5_SERVICESETTINGFACTORY_H

#include "IServiceSetting.h"

class ServiceSettingFactory : public IServiceSettings{
public:
    ServiceSettingFactory();
    std::shared_ptr<Settings> get_settings() const override;

private:
    std::shared_ptr<Settings> settings_;
};


#endif //UNTITLED5_SERVICESETTINGFACTORY_H

#include "ServiceSettingFactory.h"

ServiceSettingFactory::ServiceSettingFactory()
{
    settings = std::make_shared<Settings>();
    settings->set_port(8080);
    settings->set_default_header("Connection", "close");
    settings->set_default_header( "Access-Control-Allow-Origin", "*");
}

std::shared_ptr<Settings> ServiceSettingFactory::get_settings() const
{
    return settings;
}
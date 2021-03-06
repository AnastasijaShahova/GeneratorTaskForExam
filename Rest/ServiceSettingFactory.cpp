#include "ServiceSettingFactory.h"

ServiceSettingFactory::ServiceSettingFactory()
{
    settings_ = std::make_shared<Settings>();
    settings_->set_port(3001);
    settings_->set_default_header("Connection", "keep-alive");
    settings_->set_default_header("Content-Type", "text/plain");
    settings_->set_default_header("Access-Control-Allow-Origin", "*"); //Cors
}

std::shared_ptr<Settings> ServiceSettingFactory::get_settings() const
{
    return settings_;
}
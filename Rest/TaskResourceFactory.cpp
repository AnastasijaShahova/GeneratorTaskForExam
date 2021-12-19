//#include "TaskResourceFactory.h"
//
//TaskResourceFactory::TaskResourceFactory()
//{
//    resource_ = std::make_shared<Resource>();
//    resource_->set_path( "/topics");
//    resource_->set_method_handler("GET",
//                                  [this](const std::shared_ptr<restbed::Session> session) {
//        this->get_handler(session);
//    });
//}
//
//std::shared_ptr<Resource> TaskResourceFactory::get_resource() const
//{
//    return resource_;
//}

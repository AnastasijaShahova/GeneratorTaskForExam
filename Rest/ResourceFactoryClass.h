#ifndef UNTITLED5_RESOURCEFACTORYCLASS_H
#define UNTITLED5_RESOURCEFACTORYCLASS_H

#include "IResourceFactory.h"

class ResourceFactoryClass : public IResourceFactory {
public:
    ResourceFactoryClass();
    std::shared_ptr<IResourceFactory> chooseRecource(int param);
    int get_query_param(const std::shared_ptr<Session> session) const;


private:
    std::shared_ptr<Resource> resource_;

};


#endif //UNTITLED5_RESOURCEFACTORYCLASS_H

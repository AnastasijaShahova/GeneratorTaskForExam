#ifndef UNTITLED5_IRESOURCEFACTORY_H
#define UNTITLED5_IRESOURCEFACTORY_H
#include <memory>
#include <restbed>
using namespace restbed;

class IResourceFactory {
public:
    virtual std::shared_ptr<Resource> get_resource() const = 0;
};




#endif //UNTITLED5_IRESOURCEFACTORY_H

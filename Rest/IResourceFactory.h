#ifndef UNTITLED5_IRESOURCEFACTORY_H
#define UNTITLED5_IRESOURCEFACTORY_H
#include <memory>
#include <restbed>
#include <iostream>
using namespace restbed;

class IResourceFactory{
public:
    virtual ~IResourceFactory() { };
    virtual std::shared_ptr<Resource> get_resource() const = 0;
};




#endif //UNTITLED5_IRESOURCEFACTORY_H

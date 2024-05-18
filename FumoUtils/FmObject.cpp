#include "pch.h"
#include "FmObject.h"

FmObject* FmObject::create(void* unmanagedPointer)
{
    return nullptr;
}

ObjectFactory& ObjectFactory::instance()
{
    static ObjectFactory factory;
    return factory;
}

std::unique_ptr<FmObject> ObjectFactory::createObject(const std::string& type) const
{
    auto it = creators.find(type);
    if (it != creators.end()) {
        return it->second();
    }
    return nullptr;
}

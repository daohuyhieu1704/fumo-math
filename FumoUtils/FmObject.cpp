#include "pch.h"
#include "FmObject.h"

std::string FmObject::getObjectId() const
{
	return m_objectId;
}

void FmObject::setObjectId(const std::string& objectId)
{
	m_objectId = objectId;
}

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

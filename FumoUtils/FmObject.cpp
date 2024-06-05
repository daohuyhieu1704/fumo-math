#include "pch.h"
#include "FmObject.h"

std::string FmObject::GetObjectId() const
{
	return m_objectId;
}

void FmObject::SetObjectId(const std::string& objectId)
{
    m_objectId = objectId;
}

ObjectFactory& ObjectFactory::Instance()
{
    static ObjectFactory factory;
    return factory;
}

std::unique_ptr<FmObject> ObjectFactory::CreateObject(const std::string& type) const
{
    auto it = creators.find(type);
    if (it != creators.end()) {
        return it->second();
    }
    return nullptr;
}

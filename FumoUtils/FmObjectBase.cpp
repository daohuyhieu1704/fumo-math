#include "pch.h"
#include "FmObjectBase.h"

std::string FmObjectBase::GetObjectId() const
{
	return m_objectId;
}

void FmObjectBase::SetObjectId(const std::string& objectId)
{
    m_objectId = objectId;
}

ObjectBaseFactory& ObjectBaseFactory::Instance()
{
    static ObjectBaseFactory factory;
    return factory;
}

std::unique_ptr<FmObjectBase> ObjectBaseFactory::CreateObject(const std::string& type) const
{
    auto it = creators.find(type);
    if (it != creators.end()) {
        return it->second();
    }
    return nullptr;
}

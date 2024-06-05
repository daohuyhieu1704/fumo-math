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
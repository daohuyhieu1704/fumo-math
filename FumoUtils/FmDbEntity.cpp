#include "pch.h"
#include "FmDbEntity.h"

FmGeExtend2d FmDbEntity::GetBoundary() const
{
	return m_boundary;
}

void FmDbEntity::SetBoundary(FmGeExtend2d boundary)
{
	m_boundary = boundary;
}

FmObjectBase* FmDbEntity::Clone() const
{
	return nullptr;
}

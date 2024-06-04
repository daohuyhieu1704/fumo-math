#include "pch.h"
#include "FmGeWorldDraw.h"

namespace Geometry
{
	FmGeExtend2d FmGeWorldDraw::GetExtend() const
	{
		return m_extend;
	}
	void FmGeWorldDraw::SetExtend(FmGeExtend2d extend)
	{
		m_extend = extend;
	}

	FmGeWorldDraw::FmGeWorldDraw()
	{
	}

	FmGeWorldDraw::~FmGeWorldDraw()
	{
	}
}
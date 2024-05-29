#include "pch.h"
#include "WorldDraw.h"

namespace Geometry
{
	Extend2d WorldDraw::GetExtend() const
	{
		return m_extend;
	}
	void WorldDraw::SetExtend(Extend2d extend)
	{
		m_extend = extend;
	}

	WorldDraw::WorldDraw()
	{
	}

	WorldDraw::~WorldDraw()
	{
	}
}
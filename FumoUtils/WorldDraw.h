#pragma once
#include "Extend2d.h"

namespace Geometry
{
	class WorldDraw
	{
	private:
		Extend2d m_extend;
	public:
#pragma region Properties
		Extend2d GetExtend() const;
		void SetExtend(Extend2d extend);
#pragma endregion
		WorldDraw();
		~WorldDraw();
	};
}
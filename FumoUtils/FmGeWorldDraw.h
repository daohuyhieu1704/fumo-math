#pragma once
#include "FmGeExtend2d.h"

namespace Geometry
{
	class FmGeWorldDraw
	{
	private:
		FmGeExtend2d m_extend;
	public:
#pragma region Properties
		FmGeExtend2d GetExtend() const;
		void SetExtend(FmGeExtend2d extend);
#pragma endregion
		FmGeWorldDraw();
		~FmGeWorldDraw();
	};
}
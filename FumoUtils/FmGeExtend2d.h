#pragma once
#include "FmGePoint2d.h"

namespace Geometry
{
	class FmGeExtend2d
	{
	private:
		FmGePoint2d m_minPnt;
		FmGePoint2d m_maxPnt;
	public:
#pragma region Properties
		FmGePoint2d GetMinPnt() const;
		void SetMinPnt(FmGePoint2d minPnt);
		FmGePoint2d GetMaxPnt() const;
		void SetMaxPnt(FmGePoint2d maxPnt);
#pragma endregion

		FmGeExtend2d(FmGePoint2d minPnt, FmGePoint2d maxPnt);
		~FmGeExtend2d();
	};
}

#pragma once
#include "Point2d.h"

namespace Geometry
{
	class Extend2d
	{
	private:
		Point2d m_minPnt;
		Point2d m_maxPnt;
	public:
#pragma region Properties
		Point2d GetMinPnt() const;
		void SetMinPnt(Point2d minPnt);
		Point2d GetMaxPnt() const;
		void SetMaxPnt(Point2d maxPnt);
#pragma endregion

		Extend2d();
		~Extend2d();
	};
}

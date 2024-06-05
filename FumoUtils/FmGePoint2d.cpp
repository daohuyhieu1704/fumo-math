#include "pch.h"
#include "FmGePoint2d.h"
namespace Geometry
{
	FmGePoint2d::FmGePoint2d()
	{
		x = 0;
		y = 0;
	}

	FmGePoint2d::FmGePoint2d(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	FmGePoint2d::~FmGePoint2d()
	{
	}
}
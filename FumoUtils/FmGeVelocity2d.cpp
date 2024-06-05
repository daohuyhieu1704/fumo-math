#include "pch.h"
#include "FmGeVelocity2d.h"

namespace Geometry
{
	FmGeVelocity2d::FmGeVelocity2d()
	{
		x = 0;
		y = 0;
	}

	FmGeVelocity2d::FmGeVelocity2d(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	FmGeVelocity2d::~FmGeVelocity2d()
	{
	}
}

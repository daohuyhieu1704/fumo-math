#include "pch.h"
#include "Velocity2d.h"

namespace Geometry
{
	Velocity2d::Velocity2d()
	{
		x = 0;
		y = 0;
	}

	Velocity2d::Velocity2d(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Velocity2d::~Velocity2d()
	{
	}
}

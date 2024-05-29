#include "pch.h"
#include "Point2d.h"
namespace Geometry
{
	Point2d::Point2d()
	{
		x = 0;
		y = 0;
	}

	Point2d::Point2d(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Point2d::~Point2d()
	{
	}
}
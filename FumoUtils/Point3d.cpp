#include "pch.h"
#include "Point3d.h"

namespace Geometry
{
	Point3d::Point3d()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	Point3d::Point3d(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Point3d::~Point3d()
	{
	}
}

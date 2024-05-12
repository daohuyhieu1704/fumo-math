#include "pch.h"
#include "Point3d.h"
#include "math.h"
#include <ostream>

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

	double Point3d::DistanceTo(Point3d other) const
	{
		double dx = this->x - other.x;
		double dy = this->y - other.y;
		double dz = this->z - other.z;
		return sqrt(dx * dx + dy * dy + dz * dz);
	}

	void Point3d::operator+=(const Point3d& other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
	}

	Point3d Point3d::operator*(double scalar) const
	{
		return Point3d(this->x * scalar, this->y * scalar, this->z * scalar);
	}
}

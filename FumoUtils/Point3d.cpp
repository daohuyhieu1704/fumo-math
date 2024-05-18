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

	Point3d::Point3d(float x, float y, float z){
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Point3d::~Point3d()
	{
	}

	float Point3d::DistanceTo(Point3d other) const
	{
		float dx = this->x - other.x;
		float dy = this->y - other.y;
		float dz = this->z - other.z;
		return sqrt(dx * dx + dy * dy + dz * dz);
	}

	void Point3d::operator+=(const Point3d& other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
	}

	void Point3d::operator+=(const Velocity3d& other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;

	}

	Point3d Point3d::operator*(float scalar) const
	{
		return Point3d(this->x * scalar, this->y * scalar, this->z * scalar);
	}
}

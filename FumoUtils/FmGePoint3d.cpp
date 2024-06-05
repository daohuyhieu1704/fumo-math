#include "pch.h"
#include "FmGePoint3d.h"
#include "math.h"
#include <ostream>
#include "FmGePoint2d.h"

namespace Geometry
{
	FmGePoint3d::FmGePoint3d()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	FmGePoint3d::FmGePoint3d(float x, float y, float z){
		this->x = x;
		this->y = y;
		this->z = z;
	}

	FmGePoint3d::~FmGePoint3d()
	{
	}

	float FmGePoint3d::DistanceTo(FmGePoint3d other) const
	{
		float dx = this->x - other.x;
		float dy = this->y - other.y;
		float dz = this->z - other.z;
		return sqrt(dx * dx + dy * dy + dz * dz);
	}

	FmGePoint2d FmGePoint3d::ConvertTo2d()
	{
		return FmGePoint2d(this->x, this->y);
	}

	void FmGePoint3d::operator+=(const FmGePoint3d& other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
	}

	void FmGePoint3d::operator+=(const FmGeVelocity3d& other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;

	}

	FmGePoint3d FmGePoint3d::operator*(float scalar) const
	{
		return FmGePoint3d(this->x * scalar, this->y * scalar, this->z * scalar);
	}
}

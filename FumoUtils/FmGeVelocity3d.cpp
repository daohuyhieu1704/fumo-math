#include "pch.h"
#include "FmGeVelocity3d.h"
#include <cmath>

namespace Geometry {
	FmGeVelocity3d::FmGeVelocity3d()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	FmGeVelocity3d::FmGeVelocity3d(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	FmGeVelocity3d::~FmGeVelocity3d()
	{
	}

	float FmGeVelocity3d::Magnitude() const
	{
		return sqrt(x * x + y * y + z * z);
	}

	void FmGeVelocity3d::Normalize()
	{
		float mag = Magnitude();
		x /= mag;
		y /= mag;
		z /= mag;
	}

	FmGeVelocity3d FmGeVelocity3d::operator+=(const FmGeVelocity3d& velocity)
	{
		x += velocity.x;
		y += velocity.y;
		z += velocity.z;
		return *this;
	}

	FmGeVelocity3d FmGeVelocity3d::operator*(float scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}
}

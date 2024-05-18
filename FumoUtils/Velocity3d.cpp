#include "pch.h"
#include "Velocity3d.h"
#include <cmath>

namespace Geometry {
	Velocity3d::Velocity3d()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	Velocity3d::Velocity3d(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Velocity3d::~Velocity3d()
	{
	}

	float Velocity3d::Magnitude() const
	{
		return sqrt(x * x + y * y + z * z);
	}

	void Velocity3d::Normalize()
	{
		float mag = Magnitude();
		x /= mag;
		y /= mag;
		z /= mag;
	}

	Velocity3d Velocity3d::operator+=(const Velocity3d& velocity)
	{
		x += velocity.x;
		y += velocity.y;
		z += velocity.z;
		return *this;
	}

	Velocity3d Velocity3d::operator*(float scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}
}

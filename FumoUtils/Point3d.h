#pragma once
#include "pch.h"
#include "Velocity3d.h"
namespace Geometry
{
	class Point3d
	{
	public:
		Point3d();
		Point3d(float x, float y, float z);
		~Point3d();

		float DistanceTo(Point3d other) const;

		void operator+=(const Point3d& other);
		void operator+=(const Velocity3d& other);
		Point3d operator*(float scalar) const;

		float x;
		float y;
		float z;
	};
}


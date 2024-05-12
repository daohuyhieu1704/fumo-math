#pragma once
#include "pch.h"
#include "Velocity3d.h"
namespace Geometry
{
	class Point3d
	{
	public:
		Point3d();
		Point3d(double x, double y, double z);
		~Point3d();

		double DistanceTo(Point3d other) const;

		void operator+=(const Point3d& other);
		void operator+=(const Velocity3d& other);
		Point3d operator*(double scalar) const;

		double x;
		double y;
		double z;
	};
}


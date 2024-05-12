#pragma once
#include "pch.h"
namespace Geometry
{
	class Point3d
	{
	public:
		Point3d();
		Point3d(double x, double y, double z);
		~Point3d();

		double DistanceTo(Point3d other) const;

		double x;
		double y;
		double z;
	};
}


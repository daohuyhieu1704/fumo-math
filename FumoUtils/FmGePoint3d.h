#pragma once
#include "pch.h"
#include "FmGeVelocity3d.h"
#include "FmGePoint2d.h"

namespace Geometry
{
	class FmGePoint3d
	{
	public:
		FmGePoint3d();
		FmGePoint3d(float x, float y, float z);
		~FmGePoint3d();

		float DistanceTo(FmGePoint3d other) const;
		FmGePoint2d ConvertTo2d();

		void operator+=(const FmGePoint3d& other);
		void operator+=(const FmGeVelocity3d& other);
		bool operator==(const FmGePoint3d& other) const;
		FmGePoint3d operator*(float scalar) const;

		float x;
		float y;
		float z;
	};
}


#pragma once
namespace Geometry
{
	class FmGeVelocity3d
	{
	public:
		FmGeVelocity3d();
		FmGeVelocity3d(float x, float y, float z);
		~FmGeVelocity3d();

		float Magnitude() const;
		void Normalize();
		FmGeVelocity3d operator+=(const FmGeVelocity3d& other);
		FmGeVelocity3d operator*(float scalar);

		float x;
		float y;
		float z;
	};
}


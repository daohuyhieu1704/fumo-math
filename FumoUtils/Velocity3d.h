#pragma once
namespace Geometry
{
	class Velocity3d
	{
	public:
		Velocity3d();
		Velocity3d(float x, float y, float z);
		~Velocity3d();

		float Magnitude() const;
		void Normalize();
		Velocity3d operator+=(const Velocity3d& other);
		Velocity3d operator*(float scalar);

		float x;
		float y;
		float z;
	};
}


#pragma once
namespace Geometry
{
	class Velocity3d
	{
	public:
		Velocity3d();
		Velocity3d(double x, double y, double z);
		~Velocity3d();

		double Magnitude() const;
		void Normalize();
		Velocity3d operator+=(const Velocity3d& other);
		Velocity3d operator*(double scalar);

		double x;
		double y;
		double z;
	};
}


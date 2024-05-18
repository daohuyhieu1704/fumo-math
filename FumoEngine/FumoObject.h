#pragma once
#include "pch.h"
class FmObject abstract
{
protected:
	Geometry::Point3d Position;
	Geometry::Velocity3d Velocity;
public:
	virtual void Draw() = 0;
};


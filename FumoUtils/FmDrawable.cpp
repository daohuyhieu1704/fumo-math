#include "pch.h"
#include "FmDrawable.h"


Geometry::Point3d FmDrawable::GetPosition() const
{
	return m_position;
}

void FmDrawable::SetPosition(Geometry::Point3d position)
{
	m_position = position;
}

float FmDrawable::GetRotation() const
{
	return m_rotation;
}

void FmDrawable::SetRotation(float rotation)
{
	m_rotation = rotation;
}

void FmDrawable::SetBrush(ID2D1SolidColorBrush* brush)
{ 
	m_brush = brush;
}

ID2D1SolidColorBrush* FmDrawable::GetBrush()
{ 
	return m_brush; 
}

void FmDrawable::SetPosition(float x, float y)
{
	m_position = { x, y, 0 };
}
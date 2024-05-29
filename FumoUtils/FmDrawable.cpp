#include "pch.h"
#include "FmDrawable.h"


Geometry::Point3d FmDrawable::GetPosition() const
{
	return position;
}

void FmDrawable::SetPosition(Geometry::Point3d position)
{
	this->position = position;
}

float FmDrawable::GetRotation() const
{
	return rotation;
}

void FmDrawable::SetRotation(float rotation)
{
	this->rotation = rotation;
}

void FmDrawable::SetBrush(ID2D1SolidColorBrush* brush)
{
	brushPtr = std::make_unique<ID2D1SolidColorBrush*>(brush);
}

ID2D1SolidColorBrush* FmDrawable::GetBrush() const
{
	return *brushPtr;
}

void FmDrawable::setPosition(float x, float y)
{
    position.x = x;
    position.y = y;
}

void FmDrawable::copyFrom(const FmObject& source)
{
    const FmDrawable& drawable = dynamic_cast<const FmDrawable&>(source);
	position = drawable.position;
	rotation = drawable.rotation;
}

void FmDrawable::setRotation(float angle)
{
    rotation = angle;
}

float FmDrawable::getRotation() const
{
    return rotation;
}
#include "pch.h"
#include "FmDrawable.h"


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
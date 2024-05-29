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

void FmDrawable::SetBrush(ID2D1SolidColorBrush* brush) { 
    brushPtr.reset(new ID2D1SolidColorBrush * (brush));
}

ID2D1SolidColorBrush* FmDrawable::GetBrush() { return brushPtr ? *brushPtr : nullptr; }

void FmDrawable::SetPosition(float x, float y) {  }

void FmDrawable::copyFrom(const FmObject& source)
{
    if (const FmDrawable* srcDrawable = dynamic_cast<const FmDrawable*>(&source)) {
        position = srcDrawable->position;
        rotation = srcDrawable->rotation;
        if (srcDrawable->brushPtr) {
            SetBrush(*srcDrawable->brushPtr);
        }
    }
}
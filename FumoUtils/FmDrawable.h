#pragma once
#include "pch.h"
#include "FmObject.h"

class FmDrawable : public FmObject
{
public:
    FmDrawable() : position(0, 0, 0), rotation(0) {}
    void setPosition(float x, float y);

    Geometry::Point3d getPosition() const {
        return position;
    }
	virtual void draw(ID3D11DeviceContext* context) = 0;

    virtual void copyFrom(const FmObject& source) override;

    void setRotation(float angle);

    float getRotation() const;

protected:
    Geometry::Point3d position;
    float rotation;
};
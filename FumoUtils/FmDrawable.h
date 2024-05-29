#pragma once
#include "pch.h"
#include "FmObject.h"

class FmDrawable : public FmObject
{
protected:
    Geometry::Point3d position;
    float rotation;
    std::unique_ptr<ID2D1SolidColorBrush*> brushPtr;
public:
#pragma region Properties
	Geometry::Point3d GetPosition() const;
	void SetPosition(Geometry::Point3d position);
	float GetRotation() const;
	void SetRotation(float rotation);
	void SetBrush(ID2D1SolidColorBrush* brush);
	ID2D1SolidColorBrush* GetBrush() const;
#pragma endregion

    FmDrawable() : position(0, 0, 0), rotation(0) {}
    void setPosition(float x, float y);

    Geometry::Point3d getPosition() const {
        return position;
    }
	virtual HRESULT draw(ID3D11DeviceContext* context, ID2D1HwndRenderTarget* renderTarget) = 0;

    virtual void copyFrom(const FmObject& source) override;

    void setRotation(float angle);

    float getRotation() const;
};
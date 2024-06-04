#pragma once
#include "FmObject.h"
#include "Geometry.h"
#include <d2d1.h>
#include <d3d11.h>
#include <memory>

class FmDrawable : public FmObject {
protected:
    Geometry::FmGePoint3d position;
    float rotation;
    std::unique_ptr<ID2D1SolidColorBrush*> brushPtr;

public:
    FmDrawable() : position(0, 0, 0), rotation(0) {}
    virtual ~FmDrawable() = default;

#pragma region Properties
    Geometry::FmGePoint3d GetPosition() const;
    void SetPosition(Geometry::FmGePoint3d pos);
    void SetPosition(float x, float y);
    float GetRotation() const;
    void SetRotation(float rot);
    void SetBrush(ID2D1SolidColorBrush* brush);
    ID2D1SolidColorBrush* GetBrush();
#pragma endregion
    virtual HRESULT draw(ID3D11DeviceContext* context, ID2D1HwndRenderTarget* renderTarget) = 0;
    virtual void copyFrom(const FmObject& source) override;
};
#pragma once
#include "FmObject.h"
#include "Geometry.h"
#include <d2d1.h>
#include <d3d11.h>
#include <memory>

class FmDrawable : public FmObject {
protected:
    Geometry::Point3d m_position;
    float m_rotation;
    ID2D1SolidColorBrush* m_brush;

public:
    FmDrawable() : m_position(0, 0, 0), m_rotation(0), m_brush(nullptr) {}
    virtual ~FmDrawable() = default;

#pragma region Properties
    Geometry::Point3d GetPosition() const;
    void SetPosition(Geometry::Point3d pos);
    void SetPosition(float x, float y);
    float GetRotation() const;
    void SetRotation(float rot);
    ID2D1SolidColorBrush* GetBrush();
    void SetBrush(ID2D1SolidColorBrush* brush);
#pragma endregion
    virtual HRESULT Draw(ID2D1HwndRenderTarget* renderTarget) = 0;
    virtual FmObject* Clone() const = 0;
};
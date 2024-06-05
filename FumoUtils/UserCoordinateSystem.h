#pragma once
#include "FmDrawable.h"
#include <d2d1.h>

class UserCoordinateSystem : public FmDrawable {
public:
    UserCoordinateSystem();
    HRESULT draw(ID3D11DeviceContext* context, ID2D1HwndRenderTarget* renderTarget) override;
    void copyFrom(const FmObject& source) override;
    FmObject* clone() const override;
private:
    float unitSize;
};
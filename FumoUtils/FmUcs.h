#pragma once
#include "FmDrawable.h"
#include <d2d1.h>

class FmUcs : public FmDrawable {
public:
    FmUcs();
#pragma region Properties
    float GetUnitSize() const;
    void SetUnitSize(float size);
#pragma endregion
    HRESULT Draw(ID2D1HwndRenderTarget* renderTarget) override;
    FmObjectBase* Clone() const override;
private:
    float m_unitSize;
};


#pragma once
#include "FmDbEntity.h"

enum DragStatus {
    kNormal = 0, 
    kCancel = 1,
    kOther = 2,
    kNoChange = 3
};

class FmJig {
public:
    ID2D1SolidColorBrush* m_pBrush;
    virtual ~FmJig() {}

    virtual FmDbEntity* entity() const = 0;
    virtual DragStatus sampler() = 0;
    virtual bool update() = 0;
    virtual bool Preview(ID2D1HwndRenderTarget* pRenderTarget) = 0;

    DragStatus AcquirePoint(FmGePoint3d& point);
};
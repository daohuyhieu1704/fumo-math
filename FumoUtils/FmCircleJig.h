#pragma once
#include "FmJig.h"
#include "FmDbCircle.h"

class FmCircleJig : public FmJig {
public:
    FmCircleJig() : m_Circle(new FmDbCircle()), m_Center(FmGePoint3d(0,0,0)), m_Radius(0.0) {}

    virtual ~FmCircleJig() {
        delete m_Circle;
    }

    virtual FmDbEntity* entity() const override {
        return m_Circle;
    }

    virtual DragStatus sampler() override {
        FmGePoint3d point;
        DragStatus status = AcquirePoint(point);

        if (status == kNormal) {
            if (m_Center == FmGePoint3d(0,0,0)) {
                m_Center = point;
            }
            else {
                m_Radius = m_Center.DistanceTo(point);
            }
        }

        return status;
    }

    virtual bool update() override {
        if (m_Radius > 0) {
            m_Circle->SetCenter(m_Center);
            m_Circle->SetRadius(m_Radius);
            return true;
        }
        return false;
    }

    bool Preview(ID2D1HwndRenderTarget* pRenderTarget) override;

private:
    FmDbCircle* m_Circle;
    FmGePoint3d m_Center;
    float m_Radius;
};


#pragma once
#include "FmDbEntity.h"
#include "json.hpp"
#include <vector>
#include <memory>

using namespace Geometry;

class FmDbCircle;
typedef std::shared_ptr<FmDbCircle> FmDbCirclePtr;

class FmDbCircle : public FmDbEntity {
public:
    static FmDbCirclePtr CreateObject();
    void Initialize();
#pragma region Properties
    FmGePoint3d GetCenter() const;
    void SetCenter(FmGePoint3d center);
    void SetRadius(float r);
    float GetRadius() const;
#pragma endregion
    HRESULT Draw(ID2D1HwndRenderTarget* renderTarget) override;
    FmObjectBase* Clone() const override;
    nlohmann::json ToJson() const override;
    FmDbCircle();
private:
    float m_radius;

    FmDbCircle(const FmDbCircle&) = delete;
    FmDbCircle& operator=(const FmDbCircle&) = delete;
};

class FmDbCircleFactory {
public:
    static FmDbCirclePtr GetCircle();
private:
    static std::vector<FmDbCirclePtr> CirclePool;
};

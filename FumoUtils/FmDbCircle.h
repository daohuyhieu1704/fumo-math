#pragma once
#include "FmDbEntity.h"
#include "json.hpp"
#include <vector>
#include <memory>

class FmDbCircle;
typedef std::shared_ptr<FmDbCircle> FmDbCirclePtr;

class FmDbCircle : public FmDbEntity {
public:
    static FmDbCirclePtr CreateObject(float x, float y, float radius);
    void initialize(float x, float y, float radius);
#pragma region Properties
    Geometry::FmGePoint3d GetCenter() const;
    void SetCenter(Geometry::FmGePoint3d center);
    void setRadius(float r);
    float getRadius() const;
#pragma endregion
    HRESULT draw(ID3D11DeviceContext* context, ID2D1HwndRenderTarget* renderTarget) override;
    FmObject* clone() const override;
    nlohmann::json toJson() const override;
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

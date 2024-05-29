#pragma once
#include "FmDbEntity.h"
#include "json.hpp"
#include <vector>
#include <memory>

class FmDbCircle : public FmDbEntity {
public:
    static FmDbCircle* CreateObject(float x, float y, float radius);
    void initialize(float x, float y, float radius);
#pragma region Properties
    Geometry::Point3d GetCenter() const;
	void SetCenter(Geometry::Point3d center);
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
    static std::unique_ptr<FmDbCircle, void(*)(FmDbCircle*)> getCircle() {
        if (!circlePool.empty()) {
            std::unique_ptr<FmDbCircle, void(*)(FmDbCircle*)> circle(circlePool.back().release(), &returnCircle);
            circlePool.pop_back();
            return circle;
        }
        return std::unique_ptr<FmDbCircle, void(*)(FmDbCircle*)>(new FmDbCircle(), &returnCircle);
    }

    static void returnCircle(FmDbCircle* circle) {
        circlePool.push_back(std::unique_ptr<FmDbCircle>(circle));
    }

private:
    static std::vector<std::unique_ptr<FmDbCircle>> circlePool;
};

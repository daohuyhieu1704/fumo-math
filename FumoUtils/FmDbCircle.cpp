#include "pch.h"
#include <Windows.h>
#include "FmDbCircle.h"
#include "FmObjectBase.h"
#include "FmGePoint3d.h"

using namespace Geometry;

std::vector<FmDbCirclePtr> FmDbCircleFactory::CirclePool;

FmDbCirclePtr FmDbCircleFactory::GetCircle() {
    if (!CirclePool.empty()) {
        FmDbCirclePtr circle = CirclePool.back();
        CirclePool.pop_back();
        return circle;
    }
    else {
        return std::make_shared<FmDbCircle>();
    }
}
namespace {
    struct CircleRegistrar {
        CircleRegistrar() {
            ObjectBaseFactory::Instance().RegisterType<FmDbCircle>("Circle");
        }
    };
    static CircleRegistrar circleRegistrar;
}

FmDbCirclePtr FmDbCircle::CreateObject(float x, float y, float radius) {
    auto circle = FmDbCircleFactory::GetCircle();
    circle->Initialize(x, y, radius);
    return circle;
}

void FmDbCircle::Initialize(float x, float y, float radius) {
    SetPosition({ x, y, 0 });
    this->m_radius = radius;
}

FmGePoint3d FmDbCircle::GetCenter() const {
    return GetPosition();
}

void FmDbCircle::SetCenter(FmGePoint3d center) {
    SetPosition(center.x, center.y);
}

FmDbCircle::FmDbCircle() : m_radius(0) {}

void FmDbCircle::SetRadius(float r) {
    m_radius = r;
}

float FmDbCircle::GetRadius() const {
    return m_radius;
}

HRESULT FmDbCircle::Draw(ID2D1HwndRenderTarget* renderTarget) {
    renderTarget->BeginDraw();
    // renderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black));
    renderTarget->DrawEllipse(
        D2D1::Ellipse(D2D1::Point2F(GetCenter().x, GetCenter().y), GetRadius(), GetRadius()),
        GetBrush(),
        1.0f
    );
    return renderTarget->EndDraw();
}

FmObjectBase* FmDbCircle::Clone() const {
    return FmDbCircle::CreateObject(GetPosition().x, GetPosition().y, m_radius).get();
}

nlohmann::json FmDbCircle::ToJson() const {
    nlohmann::json json = FmDbEntity::ToJson();
    json["type"] = "Circle";
    json["radius"] = m_radius;
    return json;
}

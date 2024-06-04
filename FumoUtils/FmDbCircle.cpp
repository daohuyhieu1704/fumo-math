#include "pch.h"
#include <Windows.h>
#include "FmDbCircle.h"
#include "FmObject.h"

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
            ObjectFactory::instance().registerType<FmDbCircle>("Circle");
        }
    };
    static CircleRegistrar circleRegistrar;
}

FmDbCirclePtr FmDbCircle::CreateObject(float x, float y, float radius) {
    auto circle = FmDbCircleFactory::GetCircle();
    circle->initialize(x, y, radius);
    circle->setObjectId(DisposableWrapper::generate_short_id());
    return circle;
}

void FmDbCircle::initialize(float x, float y, float radius) {
    SetPosition({ x, y, 0 });
    this->m_radius = radius;
}

Geometry::FmGePoint3d FmDbCircle::GetCenter() const {
    return GetPosition();
}

void FmDbCircle::SetCenter(Geometry::FmGePoint3d center) {
    SetPosition(center.x, center.y);
}

FmDbCircle::FmDbCircle() : m_radius(0) {}

void FmDbCircle::setRadius(float r) {
    m_radius = r;
}

float FmDbCircle::getRadius() const {
    return m_radius;
}

HRESULT FmDbCircle::draw(ID3D11DeviceContext* context, ID2D1HwndRenderTarget* renderTarget) {
    renderTarget->BeginDraw();
    // renderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black));
    renderTarget->DrawEllipse(
        D2D1::Ellipse(D2D1::Point2F(GetCenter().x, GetCenter().y), getRadius(), getRadius()),
        GetBrush(),
        1.0f
    );
    return renderTarget->EndDraw();
}

FmObject* FmDbCircle::clone() const {
    return FmDbCircle::CreateObject(GetPosition().x, GetPosition().y, m_radius).get();
}

nlohmann::json FmDbCircle::toJson() const {
    nlohmann::json json = FmDbEntity::toJson();
    json["type"] = "Circle";
    json["radius"] = m_radius;
    return json;
}

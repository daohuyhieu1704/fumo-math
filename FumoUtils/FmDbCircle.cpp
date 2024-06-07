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

FmDbCirclePtr FmDbCircle::CreateObject() {
    auto circle = FmDbCircleFactory::GetCircle();
    return circle;
}

void FmDbCircle::Initialize() {
}

FmGePoint3d FmDbCircle::GetCenter() const {
    return GetPosition();
}

void FmDbCircle::SetCenter(FmGePoint3d center) {
    SetPosition(center.x, center.y);
}

FmDbCircle::FmDbCircle() : FmDbEntity() , m_radius(0) {}

void FmDbCircle::SetRadius(float r) {
    m_radius = r;
}

float FmDbCircle::GetRadius() const {
    return m_radius;
}

HRESULT FmDbCircle::Draw(ID2D1HwndRenderTarget* renderTarget) {
    renderTarget->BeginDraw();
    renderTarget->DrawEllipse(
        D2D1::Ellipse(D2D1::Point2F(GetCenter().x, GetCenter().y), GetRadius(), GetRadius()),
        GetBrush(),
        1.0f
    );
    return renderTarget->EndDraw();
}

void FmDbCircle::WorldDraw()
{
    FmGePoint2d minPnt(GetCenter().x - m_radius, GetCenter().y - m_radius);
    FmGePoint2d maxPnt(GetCenter().x + m_radius, GetCenter().y + m_radius);
    Geometry::FmGeExtend2d ext = Geometry::FmGeExtend2d(minPnt, maxPnt);
    SetBoundary(ext);
}

FmObjectBase* FmDbCircle::Clone() const {
    FmDbCirclePtr circleClone = FmDbCircle::CreateObject();
    circleClone->SetCenter(this->GetCenter());
    circleClone->SetRadius(this->GetRadius());
    return circleClone.get();
}

nlohmann::json FmDbCircle::ToJson() const {
    nlohmann::json json = FmDbEntity::ToJson();
    json["type"] = "Circle";
    json["radius"] = m_radius;
    return json;
}

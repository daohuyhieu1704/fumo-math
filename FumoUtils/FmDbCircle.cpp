#include "pch.h"
#include <Windows.h>
#include "FmDbCircle.h"
#include "FmObject.h"

std::vector<std::unique_ptr<FmDbCircle>> FmDbCircleFactory::circlePool;

FmDbCircle* FmDbCircle::CreateObject(float x, float y, float radius) {
    auto circle = FmDbCircleFactory::getCircle();
    circle->initialize(x, y, radius);
    return circle.release();
}

namespace {
    struct CircleRegistrar {
        CircleRegistrar() {
            ObjectFactory::instance().registerType<FmDbCircle>("Circle");
        }
    };
    static CircleRegistrar circleRegistrar;
}

void FmDbCircle::initialize(float x, float y, float radius) {
    setPosition(x, y);
    this->m_radius = radius;
}

Geometry::Point3d FmDbCircle::GetCenter() const
{
	return getPosition();
}

void FmDbCircle::SetCenter(Geometry::Point3d center)
{
	setPosition(center.x, center.y);
}

FmDbCircle::FmDbCircle()
{
    m_radius = 0;
}

void FmDbCircle::setRadius(float r) {
    m_radius = r;
}

float FmDbCircle::getRadius() const {
    return m_radius;
}

HRESULT FmDbCircle::draw(ID3D11DeviceContext* context, ID2D1HwndRenderTarget* renderTarget) {
    renderTarget->BeginDraw();
    renderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black));
    renderTarget->DrawEllipse(
        D2D1::Ellipse(D2D1::Point2F(GetCenter().x, GetCenter().x), getRadius(), getRadius()),
        GetBrush(),
        1.0f
    );
    return renderTarget->EndDraw();
}

FmObject* FmDbCircle::clone() const {
    FmDbCircle* newCircle = CreateObject(getPosition().x, getPosition().y, m_radius);
    return newCircle;
}

nlohmann::json FmDbCircle::toJson() const {
    nlohmann::json json = FmDbEntity::toJson();
    json["type"] = "Circle";
    json["radius"] = m_radius;
    return json;
}
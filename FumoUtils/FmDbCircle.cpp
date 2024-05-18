#include "pch.h"
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
    this->radius = radius;
}

void FmDbCircle::setRadius(float r) {
    radius = r;
}

float FmDbCircle::getRadius() const {
    return radius;
}

void FmDbCircle::draw(ID3D11DeviceContext* context) {
    // TODO: Implement drawing logic using DirectX
}

FmObject* FmDbCircle::clone() const {
    FmDbCircle* newCircle = CreateObject(getPosition().x, getPosition().y, radius);
    return newCircle;
}

nlohmann::json FmDbCircle::toJson() const {
    nlohmann::json json = FmDbEntity::toJson();
    json["type"] = "Circle";
    json["radius"] = radius;
    return json;
}

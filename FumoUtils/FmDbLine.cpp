#include "pch.h"
#include "FmDbLine.h"
#include "pch.h"
#include <Windows.h>
#include "FmObjectBase.h"
#include "FmGePoint3d.h"

using namespace Geometry;

std::vector<FmDbLinePtr> FmDbLineFactory::LinePool;

FmDbLinePtr FmDbLineFactory::GetLine() {
    if (!LinePool.empty()) {
        FmDbLinePtr circle = LinePool.back();
        LinePool.pop_back();
        return circle;
    }
    else {
        return std::make_shared<FmDbLine>();
    }
}
namespace {
    struct LineRegistrar {
        LineRegistrar() {
            ObjectBaseFactory::Instance().RegisterType<FmDbLine>("Line");
        }
    };
    static LineRegistrar lineRegistrar;
}

FmDbLinePtr FmDbLine::CreateObject() {
    auto circle = FmDbLineFactory::GetLine();
    return circle;
}

FmGePoint3d FmDbLine::GetStartPoint() const
{
    return m_startPoint;
}

void FmDbLine::SetStartPoint(FmGePoint3d startPnt)
{
    m_startPoint = startPnt;
    SetPosition(startPnt);
}

FmGePoint3d FmDbLine::GetEndPoint() const
{
    return m_endPoint;
}

void FmDbLine::SetEndPoint(FmGePoint3d endPnt)
{
	m_endPoint = endPnt;
}

HRESULT FmDbLine::Draw(ID2D1HwndRenderTarget* renderTarget) {
    renderTarget->BeginDraw();
    renderTarget->DrawLine(
        D2D1::Point2F(GetStartPoint().x, GetStartPoint().y),
        D2D1::Point2F(GetEndPoint().x, GetEndPoint().y),
        GetBrush(),
        1.0f
    );
    return renderTarget->EndDraw();
}

void FmDbLine::WorldDraw()
{
    Geometry::FmGeExtend2d ext = Geometry::FmGeExtend2d(GetStartPoint().ConvertTo2d(), GetEndPoint().ConvertTo2d());
    SetBoundary(ext);
}

FmObjectBase* FmDbLine::Clone() const {
    FmDbLinePtr clone = FmDbLine::CreateObject();
    clone->SetStartPoint(GetStartPoint());
    clone->SetEndPoint(GetEndPoint());
    return FmDbLine::CreateObject().get();
}

nlohmann::json FmDbLine::ToJson() const {
    nlohmann::json json = FmDbEntity::ToJson();
    json["type"] = "Line";
    json["startPoint"] = { m_startPoint.x, m_startPoint.y, m_startPoint.z };
    json["endPoint"] = { m_endPoint.x, m_endPoint.y, m_endPoint.z };
    return json;
}

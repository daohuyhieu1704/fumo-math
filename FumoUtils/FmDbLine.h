#pragma once
#include "FmDbEntity.h"
#include "FmGePoint3d.h"
#include "json.hpp"
#include <vector>
#include <memory>

using namespace Geometry;

class FmDbLine;
typedef std::shared_ptr<FmDbLine> FmDbLinePtr;

class FmDbLine : public FmDbEntity {
public:
    static FmDbLinePtr CreateObject();
#pragma region Properties
    FmGePoint3d GetStartPoint() const;
    void SetStartPoint(FmGePoint3d startPnt);
    FmGePoint3d GetEndPoint() const;
    void SetEndPoint(FmGePoint3d endPnt);
#pragma endregion
    HRESULT Draw(ID2D1HwndRenderTarget* renderTarget) override;
    FmObjectBase* Clone() const override;
    nlohmann::json ToJson() const override;
    FmDbLine() {};
private:
    FmGePoint3d m_startPoint;
    FmGePoint3d m_endPoint;
    FmDbLine(const FmDbLine&) = delete;
    FmDbLine& operator=(const FmDbLine&) = delete;
};

class FmDbLineFactory {
public:
    static FmDbLinePtr GetLine();
private:
    static std::vector<FmDbLinePtr> LinePool;
};

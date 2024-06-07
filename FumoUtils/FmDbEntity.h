#pragma once
#include "FmDbObject.h"
#include "FmGeExtend2d.h"
#include "FmGePoint2d.h"

using namespace Geometry;

class FmDbEntity : public FmDbObject
{
private:
    FmGeExtend2d m_boundary;
public:
    FmDbEntity() : FmDbObject(), m_boundary(FmGeExtend2d(FmGePoint2d({ 0,0 }), FmGePoint2d({ 0,0 }))){}
#pragma region Properties
    FmGeExtend2d GetBoundary() const;
    void SetBoundary(FmGeExtend2d boundary);
#pragma endregion
    FmObjectBase* Clone() const override;
    virtual ~FmDbEntity() = default;
};


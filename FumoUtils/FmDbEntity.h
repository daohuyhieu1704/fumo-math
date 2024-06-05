#pragma once
#include "FmDbObject.h"

class FmDbEntity : public FmDbObject
{
public:
    FmObject* Clone() const override;
    virtual ~FmDbEntity() = default;
};


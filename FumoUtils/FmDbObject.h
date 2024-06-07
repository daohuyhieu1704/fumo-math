#pragma once
#include "FmDrawable.h"
#include "json.hpp"

class FmDbObject : public FmDrawable {
public:
    FmDbObject() : FmDrawable() {}
    virtual ~FmDbObject() = default;
    virtual nlohmann::json ToJson() const;
};

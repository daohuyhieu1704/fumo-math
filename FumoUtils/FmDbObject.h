#pragma once
#include "FmDrawable.h"
#include "json.hpp"

class FmDbObject : public FmDrawable {
public:
    virtual ~FmDbObject() = default;
    virtual nlohmann::json toJson() const = 0;
};

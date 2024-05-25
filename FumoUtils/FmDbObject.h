#pragma once
#include "pch.h"
#include "FmDrawable.h"

class FmDbObject : public FmDrawable
{
public:
	virtual nlohmann::json toJson() const;
};


#pragma once
#include "pch.h"
#include "FmDrawable.h"

class FmDbObject : public FmDrawable
{
public:
	virtual void draw(ID3D11DeviceContext* context) = 0;
	virtual nlohmann::json toJson() const;
};


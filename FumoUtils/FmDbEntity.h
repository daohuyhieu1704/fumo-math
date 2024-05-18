#pragma once
#include "FmDbObject.h"

class FmDbEntity : public FmDbObject
{
public:
	FmObject* clone() const override;
	virtual void draw(ID3D11DeviceContext* context) = 0;
};


#pragma once
#include "FmDbObject.h"

class FmDbEntity : public FmDbObject
{
public:
	FmObject* clone() const override;
};


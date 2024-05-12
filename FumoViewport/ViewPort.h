#pragma once
#include "DbViewPort.h"

public ref class ViewPort
{
internal:
	ViewPort(System::IntPtr unmanagedObjPtr, bool autoDelete);
	~ViewPort();
	DbViewPort* GetImpObj();
};


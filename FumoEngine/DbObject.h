#pragma once
#include "Drawable.h"
#include "FmDbObject.h"
#include "DirectXRenderer.h"

using namespace System;

namespace FumoWrapper {

    public ref class DbObject : public Drawable
    {
    public:
        DbObject(IntPtr unmanagedObjPtr, bool autoDelete) : Drawable(IntPtr(unmanagedObjPtr), autoDelete) 
        {
            GetImpObj()->SetBrush(DirectXRenderer::GetInstance()->pBrush);
        }
        ~DbObject(){}
        property String^ Json
        {
            String^ get();
        }

    private:
        FmDbObject* GetImpObj();
    };
}
#pragma once
#include "Drawable.h"
#include "FmDbObject.h"

namespace FumoWrapper {

    public ref class DbObject : public Drawable
    {
    public:
        DbObject(FmDbObject* ptr) : Drawable(ptr) {}

        property System::String^ Json
        {
            System::String^ get();
        }

    private:
        FmDbObject* GetNativePointer();
    };
}
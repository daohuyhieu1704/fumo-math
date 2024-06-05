#pragma once
#include "ObjectBase.h"
#include "FmDrawable.h"

namespace FumoWrapper {
    public ref class Drawable : public ObjectBase
    {
    public:
        Drawable(FmDrawable* ptr) : ObjectBase(ptr) {}

        property float PositionX
        {
            float get();
            void set(float value);
        }

        property float PositionY
        {
            float get();
            void set(float value);
        }

        property float Rotation
        {
            float get();
            void set(float value);
        }

        property IntPtr Brush
        {
            IntPtr get();
            void set(IntPtr value);
        }

        void Draw(IntPtr renderTarget);

    private:
        FmDrawable* GetNativePointer();
    };
}
#include "pch.h"
#include "Drawable.h"

namespace FumoWrapper 
{
    float Drawable::PositionX::get()
    {
        return GetNativePointer()->GetPosition().x;
    }
    
    void Drawable::PositionX::set(float value)
    {
        GetNativePointer()->SetPosition(value, GetNativePointer()->GetPosition().y);
    }
    
    void Drawable::Draw(IntPtr renderTarget)
    {
        GetNativePointer()->Draw(static_cast<ID2D1HwndRenderTarget*>(renderTarget.ToPointer()));
    }

    FmDrawable* Drawable::GetNativePointer()
    {
        return static_cast<FmDrawable*>(DisposableWrapper<FmObjectBase>::GetNativePointer());
    }
    
    float Drawable::PositionY::get()
    {
        return GetNativePointer()->GetPosition().y;
    }
    
    void Drawable::PositionY::set(float value)
    {
        GetNativePointer()->SetPosition(GetNativePointer()->GetPosition().x, value);
    }
    float Drawable::Rotation::get()
    {
        return GetNativePointer()->GetRotation();
    }
    void Drawable::Rotation::set(float value)
    {
        GetNativePointer()->SetRotation(value);
    }
    IntPtr Drawable::Brush::get()
    {
        return IntPtr(GetNativePointer()->GetBrush());
    }
    void Drawable::Brush::set(IntPtr value)
    {
        GetNativePointer()->SetBrush(static_cast<ID2D1SolidColorBrush*>(value.ToPointer()));
    }
}

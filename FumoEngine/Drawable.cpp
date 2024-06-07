#include "pch.h"
#include "Drawable.h"

namespace FumoWrapper 
{
    float Drawable::PositionX::get()
    {
        return GetImpObj()->GetPosition().x;
    }
    
    void Drawable::PositionX::set(float value)
    {
        GetImpObj()->SetPosition(value, GetImpObj()->GetPosition().y);
    }
    
    void Drawable::Draw(IntPtr renderTarget)
    {
        GetImpObj()->Draw(static_cast<ID2D1HwndRenderTarget*>(renderTarget.ToPointer()));
    }

    FmDrawable* Drawable::GetImpObj()
    {
        void* obj = DisposableWrapper::GetImpObj();
        FmObjectBase* objBase = static_cast<FmObjectBase*>(obj);
        FmDrawable* objDrawable = static_cast<FmDrawable*>(objBase);
        return objDrawable;
    }
    
    float Drawable::PositionY::get()
    {
        return GetImpObj()->GetPosition().y;
    }
    
    void Drawable::PositionY::set(float value)
    {
        GetImpObj()->SetPosition(GetImpObj()->GetPosition().x, value);
    }
    float Drawable::Rotation::get()
    {
        return GetImpObj()->GetRotation();
    }
    void Drawable::Rotation::set(float value)
    {
        GetImpObj()->SetRotation(value);
    }
    IntPtr Drawable::Brush::get()
    {
        return IntPtr(GetImpObj()->GetBrush());
    }
    void Drawable::Brush::set(IntPtr value)
    {
        GetImpObj()->SetBrush(static_cast<ID2D1SolidColorBrush*>(value.ToPointer()));
    }
}

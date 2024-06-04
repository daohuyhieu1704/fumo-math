#include "pch.h"
#include "Circle.h"

void Circle::Draw(IntPtr contextPtr, IntPtr renderTargetPtr)
{
    auto context = static_cast<ID3D11DeviceContext*>(contextPtr.ToPointer());
    auto renderTarget = static_cast<ID2D1HwndRenderTarget*>(renderTargetPtr.ToPointer());
    static_cast<FmDbCircle*>(dbObject)->draw(context, renderTarget);
}

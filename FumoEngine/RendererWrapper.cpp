#include "pch.h"
#include "RendererWrapper.h"
#include "TransactionWrapper.h"
#include "Circle.h"
#include "FmGePoint3d.h"

IntPtr RendererWrapper::CreateRendererWindow(IntPtr parentHandle)
{
    HINSTANCE hInstance = GetModuleHandle(nullptr);
    m_hwnd = DirectXRenderer::getInstance().InitializeWindow(hInstance, SW_SHOW, static_cast<HWND>(parentHandle.ToPointer()));
    return IntPtr(m_hwnd);
}

void RendererWrapper::DestroyRendererWindow()
{
    if (m_hwnd != NULL) {
        DestroyWindow(m_hwnd);
        m_hwnd = NULL;
    }
}

void RendererWrapper::AddEntity()
{
    switch (Mode)
    {
    case 1: {
        auto tr = CurDoc->TransactionManager;
        tr->StartTransaction();
        try
        {
            Circle^ circle = gcnew Circle(DirectXRenderer::getInstance().MouseXY[0].x,
                DirectXRenderer::getInstance().MouseXY[0].y,
                40
            );

            GCHandle handle = GCHandle::Alloc(circle);
            IntPtr ptr = GCHandle::ToIntPtr(handle);

            tr->AddNewlyObject(circle->Id, ptr);
            tr->Commit();
            break;
        }
        catch (const std::exception&)
        {
            tr->Abort();
        }
        break;
    }
    default:
        break;
    }
}

RendererWrapper::RendererWrapper()
{
}

RendererWrapper^ RendererWrapper::CreateInstance()
{
    return gcnew RendererWrapper();
}

RendererWrapper::~RendererWrapper()
{
    DestroyRendererWindow();
}

Point3d^ RendererWrapper::CurrentMouse::get()
{
    return gcnew Point3d(DirectXRenderer::getInstance().MouseXY.back().x, DirectXRenderer::getInstance().MouseXY.back().y, DirectXRenderer::getInstance().MouseXY.back().z);
}

DatabaseInterop^ RendererWrapper::CurDoc::get()
{
    return gcnew DatabaseInterop();
}

RendererWrapper^ RendererWrapper::Instance::get()
{
    return instance->Value;
}

int RendererWrapper::Mode::get()
{
    return DirectXRenderer::getInstance().GetMode();
}

void RendererWrapper::Mode::set(int value)
{
    DirectXRenderer::getInstance().SetMode(value);
}

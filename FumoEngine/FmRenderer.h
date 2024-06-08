#pragma once
#include "pch.h"
#include "DisposableWrapper.h"
#include <DirectXRenderer.h>

using namespace System;

namespace FumoWrapper 
{
    public ref class FmRenderer : DisposableWrapper
    {
    private:
        HWND m_hwnd;
        static FmRenderer^ m_instance;
        FmRenderer() : DisposableWrapper(System::IntPtr(DirectXRenderer::GetInstance()), true) {}
    public:
        static property FmRenderer^ Instance
        {
            FmRenderer^ get()
            {
                if (m_instance == nullptr)
                {
                    m_instance = gcnew FmRenderer();
                }
                return m_instance;
            }
        }

        property String^ CurrDbName 
        {
            String^ get();
        }

        property int Mode {
            int get();
            void set(int value);
        }
        void AddEntity();
        IntPtr CreateRendererWindow(IntPtr parentHandle);
        void DestroyRendererWindow();
        void ClearScreen();
        ~FmRenderer();

        DirectXRenderer* GetImpObj()
        {
            return static_cast<DirectXRenderer*>(DisposableWrapper::GetImpObj());
        };
    };
}


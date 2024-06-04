#pragma once
#include "pch.h"
#include "DirectXRenderer.h"
#include "Point3d.h"
#include "DatabaseInterop.h"

using namespace System;
using namespace ManagedGeometry;
using namespace System::Runtime::InteropServices;

public ref class RendererWrapper
{
private:
    static RendererWrapper^ instance;
    HWND m_hwnd;
    RendererWrapper();
    static RendererWrapper^ CreateInstance();
public:
    static property RendererWrapper^ Instance
    {
        RendererWrapper^ get();
    }
   
    ~RendererWrapper();
    IntPtr CreateRendererWindow(IntPtr parentHandle);
    void DestroyRendererWindow();

    property Point3d^ CurrentMouse
    {
        Point3d^ get();
    }

    property DatabaseInterop^ CurDoc
    {
        DatabaseInterop^ get();
    }

    property int Mode {
        int get();
        void set(int value);
    }

    void AddEntity();
};


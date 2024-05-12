#pragma once
#include <windows.h>
#include "d3d11.h"
#include "dxgi.h"

using namespace System;
using namespace System::Reflection;
using namespace System::Runtime::InteropServices;

namespace ManagedWrapper {
    public ref class FmDirectX
    {
    private:
        DbDirectX* _generalDirectX;
		static IntPtr _hwnd = IntPtr::Zero;

    public:
        FmDirectX();

        ~FmDirectX();

        !FmDirectX();

        IntPtr InitializeApp(IntPtr hParent, IntPtr hInstance);

        IntPtr SetOwnWindowLong(IntPtr hWnd, int nIndex, IntPtr dwNewLong);

        void ResizeWin32Window(int x, int y, int width, int height);
    };
}

#include "pch.h"
#include "DbDirectX.h"
#include "FmDirectX.h"

namespace ManagedWrapper {

    FmDirectX::FmDirectX()
    {
        _generalDirectX = new DbDirectX();
    }
    FmDirectX::~FmDirectX()
    {
        this->!FmDirectX();
    }
    FmDirectX::!FmDirectX()
    {
        if (_generalDirectX != nullptr) {
            delete _generalDirectX;
            _generalDirectX = nullptr;
        }
    }
    IntPtr ManagedWrapper::FmDirectX::InitializeApp(IntPtr hParent, IntPtr hInstance)
    {
        HWND hwndParent = static_cast<HWND>(hParent.ToPointer());
        HINSTANCE hinstance = static_cast<HINSTANCE>(hInstance.ToPointer());
        HWND result = _generalDirectX->InitializeApp(hwndParent, hinstance);
        _hwnd = IntPtr(result);
        return _hwnd;
    }

    IntPtr ManagedWrapper::FmDirectX::SetOwnWindowLong(IntPtr hWnd, int nIndex, IntPtr dwNewLong)
    {
        HWND hwnd = static_cast<HWND>(hWnd.ToPointer());
        LONG_PTR newLong = reinterpret_cast<LONG_PTR>(dwNewLong.ToPointer());
        LONG_PTR result = _generalDirectX->SetOwnWindowLong(hwnd, nIndex, newLong);
        return IntPtr(result);
    }

    void FmDirectX::ResizeWin32Window(int x, int y, int width, int height)
    {
        if (_hwnd == IntPtr::Zero)
        {
            return;
        }
        HWND hwnd = static_cast<HWND>(_hwnd.ToPointer());
        SetWindowPos(hwnd, nullptr, x, y, width, height, SWP_NOZORDER | SWP_NOACTIVATE);
    }
}

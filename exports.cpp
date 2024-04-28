#include "pch.h"
#include "InitApp.h"

MYENGINE_API HWND InitializeApp(HWND hParent, HINSTANCE hInstance)
{
	InitialVariables();
	CreateWindowClass(hParent, hInstance);
	HWND window = InitWindow(hParent, hInstance);
	return window;
}

MYENGINE_API LONG_PTR SetOwnWindowLong(HWND hWnd, int nIndex, LONG_PTR dwNewLong)
{
    SetLastError(0);
    LONG_PTR result = SetWindowLongPtr(hWnd, nIndex, dwNewLong);
    if (result == 0) {
        DWORD dwError = GetLastError();
        if (dwError != 0) {
            return -1;
        }
    }
    return result;
}


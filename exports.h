#pragma once
#ifndef EXPORTS_H
#define EXPORTS_H

#ifdef MYENGINEDLL_EXPORTS
#define MYENGINE_API __declspec(dllexport)

#else
#define MYENGINE_API __declspec(dllimport)
#endif

extern "C" {
	MYENGINE_API int InitializeApp(HWND hParent, HINSTANCE hInstance);
	MYENGINE_API LONG_PTR SetOwnWindowLong(HWND hWnd, int nIndex, LONG_PTR dwNewLong);
}

#endif // EXPORTS_H

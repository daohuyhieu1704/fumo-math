#pragma once
#ifndef DB_DIRECTX_H
#define DB_DIRECTX_H

class DbDirectX
{
	WCHAR			WindowClass[MAX_NAME_LENGTH];
	WCHAR			WindowTitle[MAX_NAME_LENGTH];
	HICON			hIcon;
public:
	HWND InitializeApp(HWND hParent, HINSTANCE hInstance);
	LONG_PTR SetOwnWindowLong(HWND hWnd, int nIndex, LONG_PTR dwNewLong);
private:
	VOID InitialVariables();
	static LRESULT CALLBACK WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	ATOM CreateWindowClass(HWND hParent, HINSTANCE hInstance);
	HWND InitWindow(HWND hParent, HINSTANCE hInstance);
	VOID MsgLoop();
};

#endif // DB_DIRECTX_H

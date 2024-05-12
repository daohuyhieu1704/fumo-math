#pragma once
class DirectXRenderer
{
public:
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	HWND InitializeWindow(HINSTANCE hInstance, int nCmdShow, HWND parentHwnd);
};


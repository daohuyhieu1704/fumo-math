#include "pch.h"
#include "InitApp.h"

WCHAR			WindowClass[MAX_NAME_LENGTH];
WCHAR			WindowTitle[MAX_NAME_LENGTH];
HICON			hIcon;

const wchar_t g_szClassName[] = L"FumoWindowClass";

VOID InitialVariables()
{
	LoadString(NULL, IDS_APPNAME, WindowClass, MAX_NAME_LENGTH);
	LoadString(NULL, IDS_APPTITLE, WindowTitle, MAX_NAME_LENGTH);
	hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_MAINICON));
}

static LRESULT CALLBACK WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}

ATOM CreateWindowClass(HWND hParent, HINSTANCE hInstance)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	return RegisterClassEx(&wc);
}

HWND InitWindow(HWND hParent, HINSTANCE hInstance)
{
	RECT rect{};
	GetWindowRect(hParent, &rect);

	AdjustWindowRect(&rect, WS_CHILD, FALSE);
	const int top{ rect.top };
	const int left{ rect.left };
	const int width{ (rect.right - rect.left) / 2 - 100 };
	const int height{ rect.bottom - rect.top };

	HWND hWnd = CreateWindowEx(
		WS_EX_CLIENTEDGE, g_szClassName, L"Fumo Child Window",
		WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN,
		CW_USEDEFAULT, CW_USEDEFAULT, width, height,
		hParent, NULL, hInstance, NULL);

	if (!hWnd)
	{
		DWORD dwError = GetLastError();
		WCHAR szError[256];
		wsprintf(szError, L"Window Creation Failed! Error code: %lu", dwError);
		MessageBox(NULL, szError, L"Error!", MB_ICONEXCLAMATION | MB_OK);
	}
	else
	{
		ShowWindow(hWnd, SW_SHOWNORMAL);
		UpdateWindow(hWnd);
		return hWnd;
	}
	return NULL;
}


VOID MsgLoop()
{
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}
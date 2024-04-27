#include "pch.h"

/*------------------------------------------------------------------------------*/
/*	Global var																	*/
/*------------------------------------------------------------------------------*/
#pragma region Global var
WCHAR			WindowClass[MAX_NAME_LENGTH];
WCHAR			WindowTitle[MAX_NAME_LENGTH];
HICON			hIcon;
#pragma endregion
/*------------------------------------------------------------------------------*/



LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


/*------------------------------------------------------------------------------*/
/*	Declarations																*/
/*------------------------------------------------------------------------------*/
#pragma region Declarations
VOID			InitialVariables();
VOID			CreateWindowClass();
VOID			InitWindow();
VOID			MsgLoop();
#pragma endregion
/*------------------------------------------------------------------------------*/


int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{
	InitialVariables();
	CreateWindowClass();
	InitWindow();
	MsgLoop();

	return 0;
}

VOID InitialVariables()
{
	LoadString(HInstance(), IDS_APPNAME, WindowClass, MAX_NAME_LENGTH);
	LoadString(HInstance(), IDS_APPTITLE, WindowTitle, MAX_NAME_LENGTH);
	hIcon = LoadIcon(HInstance(), MAKEINTRESOURCE(IDI_MAINICON));
}

VOID CreateWindowClass()
{
	WNDCLASSEX wc{};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hIcon = hIcon;
	wc.hIconSm = hIcon;
	wc.lpszClassName = WindowClass;

	wc.lpszMenuName = nullptr;

	wc.hInstance = HInstance();

	wc.lpfnWndProc = WinProc;

	RegisterClassEx(&wc);
}

VOID InitWindow()
{
	HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, nullptr, nullptr, HInstance(), nullptr);

	if (!hWnd)
	{
		MessageBox(NULL, L"Window Creation Failed!", L"Error!", MB_ICONEXCLAMATION | MB_OK);
		return VOID();
	}

	ShowWindow(hWnd, SW_SHOW);
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

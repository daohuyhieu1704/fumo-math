#include <Windows.h>

		#define MAX_NAME_LENGTH 256
		
		WCHAR			WindowClass[MAX_NAME_LENGTH];

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{
	wcscpy_s(WindowClass, MAX_NAME_LENGTH, L"FumoEngineTest");

	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;

	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;

	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	wc.lpszClassName = WindowClass;

	wc.lpszMenuName = nullptr;

	wc.hInstance = hInstance;

	return 0;
}
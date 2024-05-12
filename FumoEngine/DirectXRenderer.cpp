#include "pch.h"
#include "DirectXRenderer.h"

using namespace Geometry;

LRESULT DirectXRenderer::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_LBUTTONDOWN:
    {
        PostMessage(GetParent(hwnd), WM_MY_MESSAGE, wParam, lParam);
        return 0; // Return 0 if you handle this message.
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        EndPaint(hwnd, &ps);
    }
    return 0;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

HWND DirectXRenderer::InitializeWindow(HINSTANCE hInstance, int nCmdShow, HWND parentHwnd)
{
    const wchar_t CLASS_NAME[] = L"DirectXWindowClass";

    // Register the window class.
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    RECT rc{};
	GetClientRect(parentHwnd, &rc);
	LONG width = rc.right - rc.left;
    LONG height = rc.bottom - rc.top;


    // Create the window.
    HWND hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,              // Extended window styles.
        CLASS_NAME,                    // Window class
        L"Drawing App",        // Window text
        WS_CHILD | WS_VISIBLE,         // Window style - make it a child window that is visible
        0, 0, width, height,                // Position and dimensions
        parentHwnd,                    // Parent window    
        NULL,                          // Menu
        hInstance,                     // Instance handle
        NULL                           // Additional application data
    );

    if (hwnd == NULL) {
        return NULL;
    }

    ShowWindow(hwnd, nCmdShow);
    InitializeDirect2D(hwnd);
    return hwnd;
}

HRESULT DirectXRenderer::InitializeDirect2D(HWND hwnd)
{

    HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pFactory);
    if (SUCCEEDED(hr))
    {
        RECT rc;
        GetClientRect(hwnd, &rc);
        D2D1_SIZE_U size = D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top);

        hr = pFactory->CreateHwndRenderTarget(
            D2D1::RenderTargetProperties(),
            D2D1::HwndRenderTargetProperties(hwnd, size),
            &pRenderTarget
        );

        if (SUCCEEDED(hr))
        {
            hr = pRenderTarget->CreateSolidColorBrush(
                D2D1::ColorF(D2D1::ColorF::Black),
                &pBrush
            );
        }
    }

    return hr;
}

void DirectXRenderer::DrawCircle(float centerX, float centerY, float radius)
{
    pRenderTarget->BeginDraw();
    pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));
    pRenderTarget->DrawEllipse(
        D2D1::Ellipse(D2D1::Point2F(centerX, centerY), radius, radius),
        pBrush,
        1.0f
    );
    HRESULT hr = pRenderTarget->EndDraw();
    if (hr == D2DERR_RECREATE_TARGET)
	{
		DiscardDeviceResources();
    }
    else if (FAILED(hr))
    {
        return;
    }
}

void DirectXRenderer::DrawGrid(float cellWidth, float cellHeight, int numColumns, int numRows)
{
	pRenderTarget->BeginDraw();
	pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));
	for (int i = 0; i < numColumns; i++)
	{
		pRenderTarget->DrawLine(
			D2D1::Point2F(i * cellWidth, 0),
			D2D1::Point2F(i * cellWidth, numRows * cellHeight),
			pBrush,
			0.5f
		);
	}
	for (int i = 0; i < numRows; i++)
	{
		pRenderTarget->DrawLine(
			D2D1::Point2F(0, i * cellHeight),
			D2D1::Point2F(numColumns * cellWidth, i * cellHeight),
			pBrush,
			1.0f
		);
	}
	HRESULT hr = pRenderTarget->EndDraw();
	if (hr == D2DERR_RECREATE_TARGET)
	{
		DiscardDeviceResources();
	}
	else if (FAILED(hr))
	{
		return;
	}
}

void DirectXRenderer::CreateDeviceIndependentResources()
{
}

void DirectXRenderer::DiscardDeviceResources()
{
	if (pRenderTarget)
	{
		pRenderTarget->Release();
		pRenderTarget = nullptr;
	}
	if (pBrush)
	{
		pBrush->Release();
		pBrush = nullptr;
	}
	if (pFactory)
	{
		pFactory->Release();
		pFactory = nullptr;
	}
}

void DirectXRenderer::CreateDeviceResources()
{
}

void DirectXRenderer::DiscardDeviceIndependentResources()
{
    if (pFactory)
    {
        pFactory->Release();
        pFactory = nullptr;
    }
}

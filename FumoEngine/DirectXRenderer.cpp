#include "pch.h"
#include "DirectXRenderer.h"
#include <windowsx.h> 
#include <chrono>
#include <iostream> // For logging

using namespace Geometry;

DirectXRenderer* DirectXRenderer::m_instance = nullptr;

DirectXRenderer* DirectXRenderer::getInstance()
{
    if (m_instance == nullptr) {
        m_instance = new DirectXRenderer();
        m_instance->Dbs.push_back(DatabaseServices::FmDatabase::CreateObject());
        m_instance->CurDoc = m_instance->Dbs[0];
        m_instance->MouseXY;
        m_instance->MouseXY.push_back({ 0, 0, 0 });
        m_instance->ucs = std::make_unique<UserCoordinateSystem>();
    }
    return m_instance;
}

DirectXRenderer::DirectXRenderer() = default;

DirectXRenderer::~DirectXRenderer() = default;

LRESULT CALLBACK DirectXRenderer::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    DirectXRenderer* pThis = nullptr;

    if (uMsg == WM_NCCREATE) {
        CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
        pThis = (DirectXRenderer*)pCreate->lpCreateParams;
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pThis);
    }
    else {
        pThis = (DirectXRenderer*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    }

    return pThis->WindowProc(hwnd, uMsg, wParam, lParam);
}

LRESULT DirectXRenderer::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_MOUSEMOVE: {
        return 0;
    }
    case WM_LBUTTONDOWN:
    {
        int xPos = GET_X_LPARAM(lParam);
        int yPos = GET_Y_LPARAM(lParam);
        OnMouseMove(xPos, yPos);
        PostMessage(GetParent(hwnd), WM_MY_MESSAGE, wParam, lParam);
        return 0;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_SIZE:
    {
        int width = LOWORD(lParam);
        int height = HIWORD(lParam);
        SetWindowPos(hwnd, NULL, 0, 0, width, height, SWP_NOZORDER | SWP_NOMOVE);
    }
    break;
    case WM_DPICHANGED:
    {
        RECT* const prcNewWindow = (RECT*)lParam;

        SetWindowPos(hwnd,
            NULL,
            prcNewWindow->left,
            prcNewWindow->top,
            prcNewWindow->right - prcNewWindow->left,
            prcNewWindow->bottom - prcNewWindow->top,
            SWP_NOZORDER | SWP_NOACTIVATE);
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        DrawUserCoordinateSystem();
        EndPaint(hwnd, &ps);
    }
    return 0;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

void DirectXRenderer::OnMouseMove(int x, int y) {
    switch (GetMode())
    {
    case 0: {
        MouseXY.clear();
        MouseXY.push_back(FmGePoint3d({ static_cast<float>(x), static_cast<float>(y), 0.0 }));
        break;
    }
    case 1: {
        MouseXY.clear();
        if (MouseXY.size() == 2) {
            MouseXY[1].x = x;
            MouseXY[1].y = y;
        }
        else {
            MouseXY.push_back(FmGePoint3d({ static_cast<float>(x), static_cast<float>(y), 0.0 }));
        }
        break;
    }
    default:
        break;
    }
}

HWND DirectXRenderer::InitializeWindow(HINSTANCE hInstance, int nCmdShow, HWND parentHwnd)
{
    const wchar_t CLASS_NAME[] = L"DirectXWindowClass";

    // Register the window class.
    WNDCLASS wc = {};
    wc.lpfnWndProc = StaticWindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));

    RegisterClass(&wc);

    RECT rc{};
    GetClientRect(parentHwnd, &rc);
    LONG width = rc.right - rc.left;
    LONG height = rc.bottom - rc.top;

    // Create the window.
    HWND hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,              // Extended window styles.
        CLASS_NAME,                    // Window class
        L"Drawing App",                // Window text
        WS_CHILD | WS_VISIBLE,         // Window style - make it a child window that is visible
        0, 0, width, height,           // Position and dimensions
        parentHwnd,                    // Parent window    
        NULL,                          // Menu
        hInstance,                     // Instance handle
        this                           // Additional application data
    );

    if (hwnd == NULL) {
        std::cerr << "Failed to create window." << std::endl;
        return NULL;
    }

    ShowWindow(hwnd, nCmdShow);

    if (FAILED(InitializeDirect2D(hwnd))) {
        std::cerr << "Failed to initialize Direct2D." << std::endl;
        DestroyWindow(hwnd);
        return NULL;
    }

    return hwnd;
}

HRESULT DirectXRenderer::InitializeDirect2D(HWND hwnd)
{
    DirectXRenderer* instance = getInstance();

    HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &instance->pFactory);
    if (FAILED(hr)) {
        std::cerr << "Failed to create D2D1Factory. HRESULT: " << hr << std::endl;
        return hr;
    }

    RECT rc;
    GetClientRect(hwnd, &rc);
    D2D1_SIZE_U size = D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top);

    hr = instance->pFactory->CreateHwndRenderTarget(
        D2D1::RenderTargetProperties(),
        D2D1::HwndRenderTargetProperties(hwnd, size),
        &instance->pRenderTarget
    );

    if (FAILED(hr)) {
        std::cerr << "Failed to create HwndRenderTarget. HRESULT: " << hr << std::endl;
        return hr;
    }

    hr = instance->pRenderTarget->CreateSolidColorBrush(
        D2D1::ColorF(D2D1::ColorF::Black),
        &instance->pBrush
    );

    if (FAILED(hr)) {
        std::cerr << "Failed to create SolidColorBrush. HRESULT: " << hr << std::endl;
        return hr;
    }

    // Set the brush for UserCoordinateSystem
    instance->ucs->SetBrush(instance->pBrush);

    return S_OK;
}

void DirectXRenderer::DrawUserCoordinateSystem()
{
    if (!pRenderTarget || !pBrush) {
        std::cerr << "pRenderTarget or pBrush is null." << std::endl;
        return;
    }

    ucs->draw(deviceContext, pRenderTarget);
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

void DirectXRenderer::ResizeWindow(HWND hwnd, int width, int height)
{
    SetWindowPos(hwnd, NULL, 0, 0, width, height, SWP_NOZORDER | SWP_NOMOVE);
}

void DirectXRenderer::DiscardDeviceIndependentResources()
{
    if (pFactory)
    {
        pFactory->Release();
        pFactory = nullptr;
    }
}

int DirectXRenderer::GetMode() {
    return getInstance()->m_mode;
}

void DirectXRenderer::SetMode(int value) {
    getInstance()->m_mode = value;
}
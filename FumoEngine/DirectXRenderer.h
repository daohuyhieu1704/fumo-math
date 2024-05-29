#pragma once
#include "pch.h"
#include <vector>
#include "FumoObject.h"

class DirectXRenderer
{
public:
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	HWND InitializeWindow(HINSTANCE hInstance, int nCmdShow, HWND parentHwnd);
    void ResizeWindow(HWND hwnd, int width, int height);
    HRESULT InitializeDirect2D(HWND hwnd);
    void DrawGrid(float cellWidth, float cellHeight, int numColumns, int numRows);
    void CreateDeviceIndependentResources();
    void CreateDeviceResources();
    void DiscardDeviceIndependentResources();
	void DiscardDeviceResources();
    ID3D11Device* device;
    ID3D11DeviceContext* deviceContext;
    ID3D11Buffer* vertexBuffer;
    ID2D1Factory* pFactory;
	ID2D1HwndRenderTarget* pRenderTarget;
    ID2D1SolidColorBrush* pBrush;
};


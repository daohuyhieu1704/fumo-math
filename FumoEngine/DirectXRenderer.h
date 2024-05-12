#pragma once
class DirectXRenderer
{
public:
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	HWND InitializeWindow(HINSTANCE hInstance, int nCmdShow, HWND parentHwnd);
    HRESULT InitializeDirect2D(HWND hwnd);
    void DrawCircle(float centerX, float centerY, float radius);
private:
	void DiscardDeviceResources();
private:
    ID3D11Device* device = nullptr;
    ID3D11DeviceContext* deviceContext = nullptr;
    ID3D11Buffer* vertexBuffer = nullptr;
    ID2D1Factory* pFactory = nullptr;
	ID2D1HwndRenderTarget* pRenderTarget = nullptr;
    ID2D1SolidColorBrush* pBrush = nullptr;
};


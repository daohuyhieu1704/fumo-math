#pragma once
#include "pch.h"
#include <vector>
#include <chrono>
#include <FmGePoint3d.h>
#include <Database.h>

class DirectXRenderer
{
public:
    static DirectXRenderer* getInstance();
    static LRESULT CALLBACK StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    void OnMouseMove(int x, int y);
	HWND InitializeWindow(HINSTANCE hInstance, int nCmdShow, HWND parentHwnd);
    void ResizeWindow(HWND hwnd, int width, int height);
    HRESULT InitializeDirect2D(HWND hwnd);
    void DrawGrid(float cellWidth, float cellHeight, int numColumns, int numRows);
    void CreateDeviceIndependentResources();
    void CreateDeviceResources();
    void DiscardDeviceIndependentResources();
	void DiscardDeviceResources();

    std::vector<Geometry::FmGePoint3d> MouseXY;

    ID3D11Device* device;
    ID3D11DeviceContext* deviceContext;
    ID3D11Buffer* vertexBuffer;
    ID2D1Factory* pFactory;
	ID2D1HwndRenderTarget* pRenderTarget;
    ID2D1SolidColorBrush* pBrush;
    DatabaseServices::FmDatabasePtr CurDoc;
    std::vector<DatabaseServices::FmDatabasePtr> Dbs;
    int GetMode();
    void SetMode(int value);
private:
    static DirectXRenderer* m_instance;
    std::chrono::steady_clock::time_point lastMouseMoveTime;

    static std::string generate_short_id();

    int throttleIntervalMs = 200;
    int m_mode = 0;

    DirectXRenderer() = default;
    ~DirectXRenderer() = default;

    DirectXRenderer(const DirectXRenderer&) = delete;
    DirectXRenderer& operator=(const DirectXRenderer&) = delete;
};


#pragma once
#include "pch.h"
#include <vector>
#include <FmDatabase.h>

using namespace DatabaseServices;

class DirectXRenderer
{
private:
    static DirectXRenderer* m_instance;
    std::vector<FmDatabasePtr> m_dbs;
    std::vector<FmGePoint2d> m_mouse_fp;
    unsigned int m_curDocIndex;
    HWND m_directWindow;
    HWND m_parent;
    int m_mode = 0;
    DirectXRenderer()
    {
        FmDatabasePtr newDb = FmDatabase::CreateObject();
        newDb->SetName("No_name");
        m_dbs.push_back(newDb);
        m_curDocIndex = 0;
    }
public:
    static DirectXRenderer* GetInstance()
    {

        if (m_instance == nullptr)
        {
            m_instance = new DirectXRenderer();
        }
        return m_instance;
    }
#pragma region Properties
    std::vector<FmGePoint2d> MouseXY() const;
    int GetMode();
    void SetMode(int value);
#pragma endregion

 static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
 HWND InitializeWindow(HINSTANCE hInstance, int nCmdShow, HWND parentHwnd);
    void ResizeWindow(HWND hwnd, int width, int height);
    HRESULT InitializeDirect2D(HWND hwnd);
    void DrawGrid(float cellWidth, float cellHeight, int numColumns, int numRows);
    void CreateDeviceIndependentResources();
    void CreateDeviceResources();
    void DiscardDeviceIndependentResources();
 void DiscardDeviceResources();
    FmDatabasePtr CurDoc();
    ID3D11Device* device;
    ID3D11DeviceContext* deviceContext;
    ID3D11Buffer* vertexBuffer;
    ID2D1Factory* pFactory;
    ID2D1HwndRenderTarget* pRenderTarget;
    ID2D1SolidColorBrush* pBrush;
};

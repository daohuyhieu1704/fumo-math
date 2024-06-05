#include "pch.h"
#include "FmRenderer.h"
#include "FmDbCircle.h"
#include "Point3d.h"


namespace FumoWrapper
{
    IntPtr FmRenderer::CreateRendererWindow(IntPtr parentHandle)
    {
        HINSTANCE hInstance = GetModuleHandle(nullptr);
        m_hwnd = GetNativePointer()->InitializeWindow(hInstance, SW_SHOW, static_cast<HWND>(parentHandle.ToPointer()));
        return IntPtr(m_hwnd);
    }

    void FmRenderer::DestroyRendererWindow()
    {
        if (m_hwnd != NULL) {
            DestroyWindow(m_hwnd);
            m_hwnd = NULL;
        }
    }

    void FmRenderer::DrawCircle(float centerX, float centerY, float radius)
    {
        FmDbCirclePtr circle = FmDbCircle::CreateObject(centerX, centerY, radius);
        GetNativePointer()->pBrush->SetColor(D2D1::ColorF(D2D1::ColorF::Red));
        circle->SetBrush(GetNativePointer()->pBrush);
        circle->SetCenter(Geometry::FmGePoint3d(centerX, centerY, 0));
        circle->Draw(GetNativePointer()->pRenderTarget);

    }

    void FmRenderer::DrawGrid(float cellWidth, float cellHeight, int numColumns, int numRows)
    {
        GetNativePointer()->DrawGrid(cellWidth, cellHeight, numColumns, numRows);
    }

    FmRenderer::~FmRenderer()
    {
        delete GetNativePointer();
        DestroyRendererWindow();
    }
}
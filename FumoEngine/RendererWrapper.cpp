#include "pch.h"
#include "RendererWrapper.h"
#include "FmDbCircle.h"

IntPtr RendererWrapper::CreateRendererWindow(IntPtr parentHandle)
{
    HINSTANCE hInstance = GetModuleHandle(nullptr);
    m_hwnd = m_renderer->InitializeWindow(hInstance, SW_SHOW, static_cast<HWND>(parentHandle.ToPointer()));
    return IntPtr(m_hwnd);
}

void RendererWrapper::DestroyRendererWindow()
{
    if (m_hwnd != NULL) {
        DestroyWindow(m_hwnd);
        m_hwnd = NULL;
    }
}

void RendererWrapper::DrawCircle(float centerX, float centerY, float radius)
{
    FmDbCirclePtr circle = FmDbCircle::CreateObject(centerX, centerY, radius);
	m_renderer->pBrush->SetColor(D2D1::ColorF(D2D1::ColorF::Red));
	circle->SetBrush(m_renderer->pBrush);
	circle->SetCenter(Geometry::Point3d(centerX, centerY, 0));
	circle->Draw(m_renderer->pRenderTarget);

}

void RendererWrapper::DrawGrid(float cellWidth, float cellHeight, int numColumns, int numRows)
{
	m_renderer->DrawGrid(cellWidth, cellHeight, numColumns, numRows);
}

RendererWrapper::~RendererWrapper()
{
    delete m_renderer;
    DestroyRendererWindow();
}

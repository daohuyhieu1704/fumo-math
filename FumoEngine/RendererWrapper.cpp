#include "pch.h"
#include "RendererWrapper.h"

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
	m_renderer->DrawCircle(centerX, centerY, radius);
}

RendererWrapper::~RendererWrapper()
{
    delete m_renderer;
    DestroyRendererWindow();
}
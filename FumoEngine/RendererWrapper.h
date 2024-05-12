#pragma once
#include "pch.h"
#include "DirectXRenderer.h"

using namespace System;

public ref class RendererWrapper
{
private:
    DirectXRenderer* m_renderer;
    HWND m_hwnd;
public:
    RendererWrapper() : m_renderer(new DirectXRenderer()) {}
    IntPtr CreateRendererWindow(IntPtr parentHandle);
    void DestroyRendererWindow();
	void DrawCircle(float centerX, float centerY, float radius);
	void DrawGrid(float cellWidth, float cellHeight, int numColumns, int numRows);
    ~RendererWrapper();
};


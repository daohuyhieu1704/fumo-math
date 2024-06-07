#include "pch.h"
#include "FmUcs.h"

FmUcs::FmUcs() : m_unitSize(30.0f) {}

float FmUcs::GetUnitSize() const
{
    return m_unitSize;
}

void FmUcs::SetUnitSize(float size)
{
    m_unitSize = size;
}

HRESULT FmUcs::Draw(ID2D1HwndRenderTarget* renderTarget) {
    if (!renderTarget || !m_brush) return E_POINTER;

    D2D1_SIZE_F rtSize = renderTarget->GetSize();
    int numColumns = static_cast<int>(rtSize.width / m_unitSize);
    int numRows = static_cast<int>(rtSize.height / m_unitSize);
    int centerColumn = numColumns / 2;
    int centerRow = numRows / 2;

    renderTarget->BeginDraw();
    renderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black));

    // Draw vertical lines
    for (int i = 0; i <= numColumns; i++) {
        float strokeWidth = (i == centerColumn) ? 4.0f : 0.5f;
        renderTarget->DrawLine(
            D2D1::Point2F(static_cast<FLOAT>(i * m_unitSize), 0.0f),
            D2D1::Point2F(static_cast<FLOAT>(i * m_unitSize), rtSize.height),
            m_brush,
            strokeWidth
        );
    }

    // Draw horizontal lines
    for (int i = 0; i <= numRows; i++) {
        float strokeWidth = (i == centerRow) ? 4.0f : 0.5f;
        renderTarget->DrawLine(
            D2D1::Point2F(0.0f, static_cast<FLOAT>(i * m_unitSize)),
            D2D1::Point2F(rtSize.width, static_cast<FLOAT>(i * m_unitSize)),
            m_brush,
            strokeWidth
        );
    }

    HRESULT hr = renderTarget->EndDraw();
    if (hr == D2DERR_RECREATE_TARGET) {
        return hr;
    }
    return S_OK;
}

FmObjectBase* FmUcs::Clone() const {
    return nullptr;
}

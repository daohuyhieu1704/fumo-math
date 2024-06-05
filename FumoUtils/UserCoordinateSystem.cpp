#include "pch.h"
#include "UserCoordinateSystem.h"

UserCoordinateSystem::UserCoordinateSystem() : unitSize(30.0f) {}

void UserCoordinateSystem::Draw(ID2D1HwndRenderTarget* pRenderTarget, ID2D1SolidColorBrush* pBrush) {
    if (!pRenderTarget || !pBrush) return;

    D2D1_SIZE_F rtSize = pRenderTarget->GetSize();
    int numColumns = static_cast<int>(rtSize.width / unitSize);
    int numRows = static_cast<int>(rtSize.height / unitSize);
    int centerColumn = numColumns / 2;
    int centerRow = numRows / 2;

    pRenderTarget->BeginDraw();
    pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));

    // Draw vertical lines
    for (int i = 0; i <= numColumns; i++) {
        float strokeWidth = (i == centerColumn) ? 4.0f : 0.5f;
        pRenderTarget->DrawLine(
            D2D1::Point2F(static_cast<FLOAT>(i * unitSize), 0.0f),
            D2D1::Point2F(static_cast<FLOAT>(i * unitSize), rtSize.height),
            pBrush,
            strokeWidth
        );
    }

    // Draw horizontal lines
    for (int i = 0; i <= numRows; i++) {
        float strokeWidth = (i == centerRow) ? 4.0f : 0.5f;
        pRenderTarget->DrawLine(
            D2D1::Point2F(0.0f, static_cast<FLOAT>(i * unitSize)),
            D2D1::Point2F(rtSize.width, static_cast<FLOAT>(i * unitSize)),
            pBrush,
            strokeWidth
        );
    }

    HRESULT hr = pRenderTarget->EndDraw();
    if (hr == D2DERR_RECREATE_TARGET) {
        // Handle target recreation if needed
    }
}
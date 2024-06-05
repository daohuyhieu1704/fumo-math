#include "pch.h"
#include "UserCoordinateSystem.h"

UserCoordinateSystem::UserCoordinateSystem() : unitSize(30.0f) {}

HRESULT UserCoordinateSystem::draw(ID3D11DeviceContext* context, ID2D1HwndRenderTarget* renderTarget) {
    if (!renderTarget || !brushPtr || !*brushPtr) return E_POINTER;

    D2D1_SIZE_F rtSize = renderTarget->GetSize();
    int numColumns = static_cast<int>(rtSize.width / unitSize);
    int numRows = static_cast<int>(rtSize.height / unitSize);
    int centerColumn = numColumns / 2;
    int centerRow = numRows / 2;

    renderTarget->BeginDraw();
    renderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));

    // Draw vertical lines
    for (int i = 0; i <= numColumns; i++) {
        float strokeWidth = (i == centerColumn) ? 4.0f : 0.5f;
        renderTarget->DrawLine(
            D2D1::Point2F(static_cast<FLOAT>(i * unitSize), 0.0f),
            D2D1::Point2F(static_cast<FLOAT>(i * unitSize), rtSize.height),
            *brushPtr,
            strokeWidth
        );
    }

    // Draw horizontal lines
    for (int i = 0; i <= numRows; i++) {
        float strokeWidth = (i == centerRow) ? 4.0f : 0.5f;
        renderTarget->DrawLine(
            D2D1::Point2F(0.0f, static_cast<FLOAT>(i * unitSize)),
            D2D1::Point2F(rtSize.width, static_cast<FLOAT>(i * unitSize)),
            *brushPtr,
            strokeWidth
        );
    }

    HRESULT hr = renderTarget->EndDraw();
    if (hr == D2DERR_RECREATE_TARGET) {
        // Handle target recreation if needed
        return hr;
    }
    return S_OK;
}

void UserCoordinateSystem::copyFrom(const FmObject& source) {
    // Implementation of copyFrom
}

FmObject* UserCoordinateSystem::clone() const {
    return nullptr;
}

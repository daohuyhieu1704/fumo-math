// UserCoordinateSystem.h
#pragma once
#include <d2d1.h>


class UserCoordinateSystem {
public:
    UserCoordinateSystem();
    void Draw(ID2D1HwndRenderTarget* pRenderTarget, ID2D1SolidColorBrush* pBrush);

private:
    float unitSize;
};
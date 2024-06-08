#include "pch.h"
#include "FmCircleJig.h"

bool FmCircleJig::Preview(ID2D1HwndRenderTarget* pRenderTarget)
{
	if (m_Radius > 0) {
		pRenderTarget->BeginDraw();
		D2D1_ELLIPSE ellipse = D2D1::Ellipse(D2D1::Point2F(m_Center.x, m_Center.y), m_Radius, m_Radius);
		pRenderTarget->DrawEllipse(ellipse, m_pBrush);
		pRenderTarget->EndDraw();
		return true;
	}
	return false;
}

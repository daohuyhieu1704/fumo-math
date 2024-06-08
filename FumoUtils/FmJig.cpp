#include "pch.h"
#include "FmJig.h"
#include "DirectXRenderer.h"

DragStatus FmJig::AcquirePoint(FmGePoint3d& point)
{
    if (true) {
        std::vector<FmGePoint2d> mouse = DirectXRenderer::GetInstance()->MouseXY();
        if (mouse.size() > 0) {
			point = FmGePoint3d(mouse[mouse.size() - 1].x, mouse[mouse.size() - 1].y, 0);
			return kNormal;
		}
    }
    return kCancel;
}

#pragma once
#include "DisposableWrapper.h"
#include "FmGePoint2d.h"

using namespace Geometry;

namespace FumoWrapper
{
	namespace Geo
	{
		public ref class Point2d : public DisposableWrapper<FmGePoint2d>
		{
        public:
            Point2d() : DisposableWrapper(new FmGePoint2d()) {}
            Point2d(FmGePoint2d* pnt) : DisposableWrapper(pnt) {}
            Point2d(float x, float y) : DisposableWrapper(new FmGePoint2d(x, y)) {}

            property float X
            {
                float get()
                {
                    return GetNativePointer()->x;
                }
                void set(float value)
                {
                    GetNativePointer()->x = value;
                }
            }

            property float Y
            {
                float get()
                {
                    return GetNativePointer()->y;
                }
                void set(float value)
                {
                    GetNativePointer()->y = value;
                }
            }
		};
	}
}

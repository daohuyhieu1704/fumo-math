#pragma once
#include "FmGePoint2d.h"

using namespace Geometry;

namespace FumoWrapper
{
    namespace Geo
    {
        public value class Point2d
        {
        private:
            float x;
            float y;

        public:
            Point2d(float x, float y) : x(x), y(y) {}

            property float X
            {
                float get()
                {
                    return x;
                }
                void set(float value)
                {
                    x = value;
                }
            }

            property float Y
            {
                float get()
                {
                    return y;
                }
                void set(float value)
                {
                    y = value;
                }
            }

            FmGePoint2d ToNative()
            {
                return FmGePoint2d(x, y);
            }

            static Point2d FromNative(FmGePoint2d point)
            {
                return Point2d(point.x, point.y);
            }
        };
    }
}

#pragma once
#include "FmGeExtend2d.h"
#include "Point2d.h"

namespace FumoWrapper {
    namespace Geo {
        public value class Extend2d
        {
        private:
            Point2d minPnt;
            Point2d maxPnt;

        public:
            Extend2d(Point2d min, Point2d max) : minPnt(min), maxPnt(max) {}

            property Point2d MinPnt
            {
                Point2d get()
                {
                    return minPnt;
                }
                void set(Point2d value)
                {
                    minPnt = value;
                }
            }

            property Point2d MaxPnt
            {
                Point2d get()
                {
                    return maxPnt;
                }
                void set(Point2d value)
                {
                    maxPnt = value;
                }
            }

            Geometry::FmGeExtend2d ToNative()
            {
                return Geometry::FmGeExtend2d(minPnt.ToNative(), maxPnt.ToNative());
            }

            static Extend2d FromNative(Geometry::FmGeExtend2d extend)
            {
                return Extend2d(Point2d::FromNative(extend.GetMinPnt()), Point2d::FromNative(extend.GetMaxPnt()));
            }
        };
    }
}

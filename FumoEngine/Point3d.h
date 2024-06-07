#pragma once
#include "FmGePoint3d.h"
#include "Point2d.h"

using namespace Geometry;

namespace FumoWrapper
{
    namespace Geo
    {
        public value class Point3d
        {
        private:
            float x;
            float y;
            float z;

        public:
            Point3d(float x, float y, float z) : x(x), y(y), z(z) {}

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

            property float Z
            {
                float get()
                {
                    return z;
                }
                void set(float value)
                {
                    z = value;
                }
            }

            float DistanceTo(Point3d other)
            {
                FmGePoint3d thisPoint(x, y, z);
                FmGePoint3d otherPoint(other.x, other.y, other.z);
                return thisPoint.DistanceTo(otherPoint);
            }

            Point2d ConvertTo2d()
            {
                FmGePoint3d thisPoint(x, y, z);
                FmGePoint2d native2d = thisPoint.ConvertTo2d();
                return Point2d(native2d.x, native2d.y);
            }

            void Add(Point3d other)
            {
                x += other.x;
                y += other.y;
                z += other.z;
            }

            void AddVelocity(Point3d velocity)
            {
                x += velocity.x;
                y += velocity.y;
                z += velocity.z;
            }

            Point3d Multiply(float scalar)
            {
                return Point3d(x * scalar, y * scalar, z * scalar);
            }

            FmGePoint3d ToNative() {
                return FmGePoint3d(x, y, z);
            }

            static Point3d FromNative(FmGePoint3d point)
            {
                return Point3d(point.x, point.y, point.z);
            }
        };
    }
}

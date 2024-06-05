#pragma once
#include "DisposableWrapper.h"
#include "FmGePoint3d.h"
#include "Point2d.h"

using namespace Geometry;

namespace FumoWrapper
{
    namespace Geo
    {
        public ref class Point3d : public DisposableWrapper<FmGePoint3d>
        {
        public:
            Point3d() : DisposableWrapper(new FmGePoint3d()) {}
            Point3d(FmGePoint3d* pnt) : DisposableWrapper(pnt) {}
            Point3d(float x, float y, float z) : DisposableWrapper(new FmGePoint3d(x, y, z)) {}

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

            property float Z
            {
                float get()
                {
                    return GetNativePointer()->z;
                }
                void set(float value)
                {
                    GetNativePointer()->z = value;
                }
            }

            float DistanceTo(Point3d^ other)
            {
                return GetNativePointer()->DistanceTo(*other->GetNativePointer());
            }

            Point2d^ ConvertTo2d()
            {
                auto native2d = GetNativePointer()->ConvertTo2d();
                return gcnew Point2d(native2d.x, native2d.y);
            }

            void Add(Point3d^ other)
            {
                *GetNativePointer() += *other->GetNativePointer();
            }

            void AddVelocity(Point3d^ velocity)
            {
                *GetNativePointer() += *velocity->GetNativePointer();
            }

            Point3d^ Multiply(float scalar)
            {
                Geometry::FmGePoint3d result = GetNativePointer()->operator*(scalar);
                return gcnew Point3d(result.x, result.y, result.z);
            }

        private:
            FmGePoint3d* GetNativePointer()
            {
                return static_cast<FmGePoint3d*>(DisposableWrapper<FmGePoint3d>::GetNativePointer());
            }
        };
    }
}

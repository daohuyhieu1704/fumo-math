#pragma once
#include "DisposableWrapper.h"
#include "FmGeExtend2d.h"
#include "Point2d.h"

namespace FumoWrapper {
    namespace Geo {
        public ref class Extend2d : public DisposableWrapper<Geometry::FmGeExtend2d>
        {
        public:
            Extend2d() : DisposableWrapper(new Geometry::FmGeExtend2d(Geometry::FmGePoint2d(), Geometry::FmGePoint2d())) {}
            Extend2d(Point2d^ min, Point2d^ max) : DisposableWrapper(new Geometry::FmGeExtend2d(*min->GetNativePointer(), *max->GetNativePointer())) {}

            property Point2d^ MinPnt
            {
                Point2d^ get()
                {
                    Geometry::FmGePoint2d lim = GetNativePointer()->GetMinPnt();
                    return gcnew Point2d(lim.x, lim.y);
                }
                void set(Point2d^ value)
                {
                    GetNativePointer()->SetMinPnt(*value->GetNativePointer());
                }
            }

            property Point2d^ MaxPnt
            {
                Point2d^ get()
                {
                    Geometry::FmGePoint2d lam = GetNativePointer()->GetMaxPnt();
                    return gcnew Point2d(lam.x, lam.y);
                }
                void set(Point2d^ value)
                {
                    GetNativePointer()->SetMaxPnt(*value->GetNativePointer());
                }
            }

        private:
            Geometry::FmGeExtend2d* GetNativePointer()
            {
                return static_cast<Geometry::FmGeExtend2d*>(DisposableWrapper<Geometry::FmGeExtend2d>::GetNativePointer());
            }
        };
    }
}

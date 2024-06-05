#pragma once
#include "ObjectBase.h"
#include "FmDbEntity.h"
#include "Point2d.h"
#include "Extend2d.h"


namespace FumoWrapper {
    using namespace Geo;

    public ref class DbEntity : public ObjectBase
    {
    public:
        DbEntity(FmDbEntity* ptr) : ObjectBase(ptr) {}

        property Extend2d^ Boundary
        {
            Extend2d^ get()
            {
                Geometry::FmGeExtend2d ext = GetNativePointer()->GetBoundary();
                Geometry::FmGePoint2d extMin = ext.GetMinPnt();
                Geometry::FmGePoint2d extMax = ext.GetMaxPnt();
                return gcnew Extend2d(gcnew Point2d(extMin.x, extMin.y), gcnew Point2d(extMax.x, extMax.y));
            }
            void set(Extend2d^ value)
            {
                GetNativePointer()->SetBoundary(*value->GetNativePointer());
            }
        }

    private:
        FmDbEntity* GetNativePointer()
        {
            return static_cast<FmDbEntity*>(DisposableWrapper<FmObjectBase>::GetNativePointer());
        }
    };
}

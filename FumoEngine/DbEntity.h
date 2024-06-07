#pragma once
#include "DbObject.h"
#include "FmDbEntity.h"
#include "Point2d.h"
#include "Extend2d.h"


namespace FumoWrapper {
    using namespace Geo;

    public ref class DbEntity : public DbObject
    {
    public:
        DbEntity(IntPtr unmanagedObjPtr, bool autoDelete) : DbObject(System::IntPtr(unmanagedObjPtr), autoDelete) {}
        ~DbEntity(){}
        property Extend2d Boundary
        {
            Extend2d get()
            {
                return Extend2d::FromNative(GetImpObj()->GetBoundary());
            }
            void set(Extend2d value)
            {
                GetImpObj()->SetBoundary(value.ToNative());
            }
        }

    private:
        FmDbEntity* GetImpObj()
        {
            void* obj = DisposableWrapper::GetImpObj();
            FmObjectBase* objBase = static_cast<FmObjectBase*>(obj);
            FmDrawable* objDrawable = static_cast<FmDrawable*>(objBase);
            FmDbObject* objDb = static_cast<FmDbObject*>(objDrawable);
            FmDbEntity* objEntity = static_cast<FmDbEntity*>(objDb);
            return objEntity;
        }
    };
}

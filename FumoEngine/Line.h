#pragma once
#include "DbEntity.h"
#include "FmDbLine.h"
#include "Point3d.h"
#include "FmRenderer.h"

namespace FumoWrapper {

    public ref class Line : public DbEntity
    {
    public:
        Line(IntPtr unmanagedObjPtr, bool autoDelete) : DbEntity(System::IntPtr(unmanagedObjPtr), autoDelete) {}
        Line(Point3d startPnt, Point3d endPnt)
            : DbEntity(System::IntPtr(new FmDbLine()), true)
        {
            StartPnt = startPnt;
            EndPnt = endPnt;
        }

        property Point3d StartPnt
        {
            Point3d get()
            {
                return Point3d::FromNative(GetImpObj()->GetStartPoint());
            }
            void set(Point3d value)
            {
                GetImpObj()->SetStartPoint(value.ToNative());
            }
        }

        property Point3d EndPnt
        {
            Point3d get()
            {
                return Point3d::FromNative(GetImpObj()->GetEndPoint());
            }
            void set(Point3d value)
            {
                GetImpObj()->SetEndPoint(value.ToNative());
            }
        }

        void Draw(IntPtr renderTarget)
        {
            GetImpObj()->Draw(static_cast<ID2D1HwndRenderTarget*>(renderTarget.ToPointer()));
        }

        ObjectBase^ Clone() override
        {
            return gcnew ObjectBase(System::IntPtr(GetImpObj()->Clone()), true);
        }

        property System::String^ Json
        {
            System::String^ get()
            {
                nlohmann::json json = GetImpObj()->ToJson();
                std::string jsonString = json.dump();
                return gcnew System::String(jsonString.c_str());
            }
        }

    private:
        FmDbLine* GetImpObj()
        {
            void* obj = DisposableWrapper::GetImpObj();
            FmObjectBase* objBase = static_cast<FmObjectBase*>(obj);
            FmDrawable* objDrawable = static_cast<FmDrawable*>(objBase);
            FmDbObject* objDb = static_cast<FmDbObject*>(objDrawable);
            FmDbEntity* objEntity = static_cast<FmDbEntity*>(objDb);
            FmDbLine* line = static_cast<FmDbLine*>(objEntity);
            return line;
        }
    };
}

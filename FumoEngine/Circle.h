#pragma once
#include "DbEntity.h"
#include "FmDbCircle.h"
#include "Point3d.h"
#include "FmRenderer.h"

namespace FumoWrapper {

    public ref class Circle : public DbEntity
    {
    public:
        Circle(IntPtr unmanagedObjPtr, bool autoDelete) : DbEntity(System::IntPtr(unmanagedObjPtr), autoDelete) {}
        Circle(Point3d center, double radius) 
            : Circle(System::IntPtr(new FmDbCircle()), true)
        {
            Center = center;
            Radius = radius;
        }
        ~Circle(){}
        property Point3d Center
        {
            Point3d get()
            {
                return Point3d::FromNative(GetImpObj()->GetCenter());
            }
            void set(Point3d value)
            {
                GetImpObj()->SetCenter(value.ToNative());
            }
        }

        property float Radius
        {
            float get()
            {
                return GetImpObj()->GetRadius();
            }
            void set(float value)
            {
                GetImpObj()->SetRadius(value);
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
        FmDbCircle* GetImpObj()
        {
            void* obj = ObjectBase::GetImpObj();
            FmDbCircle* circle = static_cast<FmDbCircle*>(obj);
            return circle;
        }
    };
}

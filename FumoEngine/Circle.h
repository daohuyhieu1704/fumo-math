#pragma once
#include "DbEntity.h"
#include "FmDbCircle.h"
#include "Point3d.h"

namespace FumoWrapper {

    public ref class Circle : public DbEntity
    {
    public:
        Circle(FmDbCircle* ptr) : DbEntity(ptr) {}

        property Point3d^ Center
        {
            Point3d^ get()
            {
                Geometry::FmGePoint3d pnt = GetNativePointer()->GetCenter();
                return gcnew Point3d(pnt.x, pnt.y, pnt.z);
            }
            void set(Point3d^ value)
            {
                GetNativePointer()->SetCenter(*value->GetNativePointer());
            }
        }

        property float Radius
        {
            float get()
            {
                return GetNativePointer()->GetRadius();
            }
            void set(float value)
            {
                GetNativePointer()->SetRadius(value);
            }
        }

        void Draw(IntPtr renderTarget)
        {
            GetNativePointer()->Draw(static_cast<ID2D1HwndRenderTarget*>(renderTarget.ToPointer()));
        }

        Circle^ Clone()
        {
            return gcnew Circle(dynamic_cast<FmDbCircle*>(GetNativePointer()->Clone()));
        }

        property System::String^ Json
        {
            System::String^ get()
            {
                nlohmann::json json = GetNativePointer()->ToJson();
                std::string jsonString = json.dump();
                return gcnew System::String(jsonString.c_str());
            }
        }

    private:
        FmDbCircle* GetNativePointer()
        {
            return static_cast<FmDbCircle*>(DisposableWrapper<FmObjectBase>::GetNativePointer());
        }
    };
}

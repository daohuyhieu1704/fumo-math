#pragma once
#include "DbEntity.h"
#include "FmDbLine.h"
#include "Point3d.h"
#include "FmRenderer.h"

namespace FumoWrapper {

    public ref class Line : public DbEntity
    {
    public:
        Line() : DbEntity(FmDbLine::CreateObject().get()) {}
        Line(FmDbLine* ptr) : DbEntity(ptr) {}

        property Point3d^ StartPnt
        {
            Point3d^ get()
            {
                Geometry::FmGePoint3d pnt = GetNativePointer()->GetStartPoint();
                return gcnew Point3d(pnt.x, pnt.y, pnt.z);
            }
            void set(Point3d^ value)
            {
                GetNativePointer()->SetStartPoint(*value->GetNativePointer());
            }
        }

        property Point3d^ EndPnt
        {
            Point3d^ get()
            {
                Geometry::FmGePoint3d pnt = GetNativePointer()->GetEndPoint();
                return gcnew Point3d(pnt.x, pnt.y, pnt.z);
            }
            void set(Point3d^ value)
            {
                GetNativePointer()->SetEndPoint(*value->GetNativePointer());
            }
        }

        void Draw(IntPtr renderTarget)
        {
            GetNativePointer()->Draw(static_cast<ID2D1HwndRenderTarget*>(renderTarget.ToPointer()));
        }

        Line^ Clone()
        {
            return gcnew Line(dynamic_cast<FmDbLine*>(GetNativePointer()->Clone()));
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
        FmDbLine* GetNativePointer()
        {
            return static_cast<FmDbLine*>(DisposableWrapper<FmObjectBase>::GetNativePointer());
        }
    };
}

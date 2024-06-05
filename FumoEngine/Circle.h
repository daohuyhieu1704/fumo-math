#pragma once
#include "FmDbCircle.h"
#include "DbObject.h"
#include <msclr/marshal_cppstd.h>

using namespace System;

public ref class Circle : public DbObject
{
public:
    Circle(float x, float y, float radius)
        : DbObject(FmDbCircle::CreateObject(x, y, radius).get()) {
        X = x;
        Y = y;
        Radius = radius;
    }

    ~Circle() {
        this->!Circle();
    }

    !Circle() {
    }

    property String^ Id {
        String^ get() {
            return msclr::interop::marshal_as<String^>(dbObject->getObjectId());
        }
    }

    property float X {
        float get() {
            return static_cast<FmDbCircle*>(dbObject)->GetCenter().x;
        }
        void set(float value) {
            auto center = static_cast<FmDbCircle*>(dbObject)->GetCenter();
            center.x = value;
            static_cast<FmDbCircle*>(dbObject)->SetCenter(center);
        }
    }

    property float Y {
        float get() {
            return static_cast<FmDbCircle*>(dbObject)->GetCenter().y;
        }
        void set(float value) {
            auto center = static_cast<FmDbCircle*>(dbObject)->GetCenter();
            center.y = value;
            static_cast<FmDbCircle*>(dbObject)->SetCenter(center);
        }
    }

    property float Radius {
        float get() {
            return static_cast<FmDbCircle*>(dbObject)->getRadius();
        }
        void set(float value) {
            static_cast<FmDbCircle*>(dbObject)->setRadius(value);
        }
    }

    FmDbCircle* GetImpObj();
private:
    void Draw(IntPtr contextPtr, IntPtr renderTargetPtr);
};


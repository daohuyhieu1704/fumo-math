#pragma once

#include "FmGePoint3d.h"

using namespace System;

namespace ManagedGeometry {
	public ref class Point3d
	{
	private:
		Geometry::FmGePoint3d* point3d;
    public:
        Point3d() {
            point3d = new Geometry::FmGePoint3d();
        }

        Point3d(float x, float y, float z) {
            point3d = new Geometry::FmGePoint3d(x, y, z);
        }

        ~Point3d() {
            this->!Point3d();
        }

        !Point3d() {
            delete point3d;
        }

        property float X {
            float get() {
                return point3d->x;
            }
            void set(float value) {
                point3d->x = value;
            }
        }

        property float Y {
            float get() {
                return point3d->y;
            }
            void set(float value) {
                point3d->y = value;
            }
        }

        property float Z {
            float get() {
                return point3d->z;
            }
            void set(float value) {
                point3d->z = value;
            }
        }
	};
}
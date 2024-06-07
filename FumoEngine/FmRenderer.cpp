#include "pch.h"
#include "FmRenderer.h"
#include "FmDbCircle.h"
#include "Point3d.h"
#include "Trans.h"
#include "Circle.h"
#include "Line.h"

namespace FumoWrapper
{
    using namespace DbServices;

    void FmRenderer::AddEntity()
    {
        DirectXRenderer* ins = GetImpObj();
        std::vector<Geometry::FmGePoint2d> pntList = ins->MouseXY();
        if (pntList.size() < 2) {
            return;
        }
        Trans^ trans = gcnew Trans();
        trans->StartTransaction();
        switch (Mode)
        {
        case 1: {
            try
            {
                // DrawCircle(10, 10, 50);
                Geometry::FmGePoint2d pnt1 = pntList[pntList.size() - 2];
                Geometry::FmGePoint2d pnt2 = pntList.back();
                Point3d center = Point3d(pnt1.x, pnt1.y, 0);
                Point3d boundPnt = Point3d(pnt2.x, pnt2.y, 0);
                Circle^ circle = gcnew Circle(center, center.DistanceTo(boundPnt));
                trans->AddNewlyObject(circle);
                trans->Commit();
                break;
            }
            catch (const std::exception&)
            {
                trans->Abort();
            }
            break;
        }
        case 2: {
            try
            {
                DirectXRenderer* ins = GetImpObj();
                Geometry::FmGePoint2d pnt1 = pntList[pntList.size() - 2];
                Geometry::FmGePoint2d pnt2 = pntList.back();
                Point3d StartPnt = Point3d(pnt1.x, pnt1.y, 0);
                Point3d EndPnt = Point3d(pnt2.x, pnt2.y, 0);

                Line^ line = gcnew Line(StartPnt, EndPnt);
                trans->AddNewlyObject(line);
                trans->Commit();
                break;
            }
            catch (const std::exception&)
            {
                trans->Abort();
            }
            break;
        }
        default:
            break;
        }
    }
    IntPtr FmRenderer::CreateRendererWindow(IntPtr parentHandle)
    {
        HINSTANCE hInstance = GetModuleHandle(nullptr);
        m_hwnd = GetImpObj()->InitializeWindow(hInstance, SW_SHOW, static_cast<HWND>(parentHandle.ToPointer()));
        return IntPtr(m_hwnd);
    }

    void FmRenderer::DestroyRendererWindow()
    {
        if (m_hwnd != NULL) {
            DestroyWindow(m_hwnd);
            m_hwnd = NULL;
        }
    }

    void FmRenderer::ClearScreen()
    {
        GetImpObj()->ClearScreen();
    }

    FmRenderer::~FmRenderer()
    {
        delete GetImpObj();
        DestroyRendererWindow();
    }

    String^ FmRenderer::CurrDbName::get()
    {
        return gcnew String(GetImpObj()->GetInstance()->CurDoc()->GetName().c_str());
    }

    int FmRenderer::Mode::get()
    {
        return GetImpObj()->GetInstance()->GetMode();
    }

    void FmRenderer::Mode::set(int value)
    {
        return GetImpObj()->GetInstance()->SetMode(value);
    }
}
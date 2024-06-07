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
        DirectXRenderer* ins = GetNativePointer();
        std::vector<Geometry::FmGePoint2d> pntList = ins->MouseXY();
        if (pntList.size() < 2) {
            return;
        }
        switch (Mode)
        {
        case 1: {
            try
            {
                DrawCircle(10, 10, 50);
                //Circle^ circle = gcnew Circle();
                //Geometry::FmGePoint2d pnt1 = pntList[pntList.size() - 2];
                //Geometry::FmGePoint2d pnt2 = pntList.back();
                //circle->Center = gcnew Point3d(pnt1.x, pnt1.y, 0);
                //Point3d^ p2 = gcnew Point3d(pnt2.x, pnt2.y, 0);
                //circle->Radius = circle->Center->DistanceTo(p2) / 2;
                //dynamic_cast<FmDbCircle*>(circle->GetNativePointer())->Draw(GetNativePointer()->pRenderTarget);
                //trans->AddNewlyObject(circle->ObjectId, circle);
                //trans->Commit();
                break;
            }
            catch (const std::exception&)
            {
            }
            break;
        }
        case 2: {
            Trans^ trans = gcnew Trans();
            try
            {
                Line^ line = gcnew Line();

                DirectXRenderer* ins = GetNativePointer();
                Geometry::FmGePoint2d pnt1 = pntList[pntList.size() - 2];
                Geometry::FmGePoint2d pnt2 = pntList.back();
                line->StartPnt = gcnew Point3d(pnt1.x, pnt1.y, 0);
                line->EndPnt = gcnew Point3d(pnt2.x, pnt2.y, 0);
                line->Draw(IntPtr(GetNativePointer()->pRenderTarget));

                trans->AddNewlyObject(line->ObjectId, line);
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
        m_hwnd = GetNativePointer()->InitializeWindow(hInstance, SW_SHOW, static_cast<HWND>(parentHandle.ToPointer()));
        return IntPtr(m_hwnd);
    }

    void FmRenderer::DestroyRendererWindow()
    {
        if (m_hwnd != NULL) {
            DestroyWindow(m_hwnd);
            m_hwnd = NULL;
        }
    }

    void FmRenderer::DrawCircle(float centerX, float centerY, float radius)
    {
        FmDbCirclePtr circle = FmDbCircle::CreateObject(centerX, centerY, radius);
        GetNativePointer()->pBrush->SetColor(D2D1::ColorF(D2D1::ColorF::Red));
        circle->SetBrush(GetNativePointer()->pBrush);

        DirectXRenderer* ins = GetNativePointer();
        Geometry::FmGePoint2d pnt = ins->MouseXY().back();
        circle->SetCenter(Geometry::FmGePoint3d(pnt.x, pnt.y, 0));

        circle->Draw(GetNativePointer()->pRenderTarget);
        GetNativePointer()->CurDoc()->TransactionManager->StartTransaction();
        GetNativePointer()->CurDoc()->TransactionManager->AddNewlyObject(circle->GetObjectId(), circle);
        GetNativePointer()->CurDoc()->TransactionManager->Commit();
    }

    void FmRenderer::DrawGrid(float cellWidth, float cellHeight, int numColumns, int numRows)
    {
        GetNativePointer()->DrawGrid(cellWidth, cellHeight, numColumns, numRows);
    }

    FmRenderer::~FmRenderer()
    {
        delete GetNativePointer();
        DestroyRendererWindow();
    }

    String^ FmRenderer::CurrDbName::get()
    {
        return gcnew String(GetNativePointer()->GetInstance()->CurDoc()->GetName().c_str());
    }

    int FmRenderer::Mode::get()
    {
        return GetNativePointer()->GetInstance()->GetMode();
    }

    void FmRenderer::Mode::set(int value)
    {
        return GetNativePointer()->GetInstance()->SetMode(value);
    }
}
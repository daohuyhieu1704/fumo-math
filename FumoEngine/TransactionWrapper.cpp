#include "pch.h"
#include "TransactionWrapper.h"
#include "DatabaseInterop.h"
#include "FmObject.h"
#include "Circle.h"

using namespace DatabaseServices;
using namespace msclr::interop;

TransactionWrapper::TransactionWrapper()
{
    if (DirectXRenderer::getInstance()->CurDoc->TransactionManager == nullptr) {
        DirectXRenderer::getInstance()->CurDoc->TransactionManager = std::make_unique<FmTransaction>(DirectXRenderer::getInstance()->CurDoc);
    }
    transaction = DirectXRenderer::getInstance()->CurDoc->TransactionManager.get();
}

TransactionWrapper::TransactionWrapper(DatabaseServices::FmDatabasePtr parentDoc)
{
    transaction = new DatabaseServices::FmTransaction(parentDoc);
}

TransactionWrapper::~TransactionWrapper()
{
    this->!TransactionWrapper();
}

TransactionWrapper::!TransactionWrapper()
{
}

void TransactionWrapper::StartTransaction()
{
    transaction->StartTransaction(DirectXRenderer::getInstance()->deviceContext, DirectXRenderer::getInstance()->pRenderTarget);
}

void TransactionWrapper::AddNewlyObject(DbObject^ objPtr)
{
    Circle^ circle = safe_cast<Circle^>(objPtr);
    if (circle == nullptr) {
        throw gcnew ArgumentException("Invalid objPtr");
    }

    try {
        FmDbCircle* imp = circle->GetImpObj();
        imp->SetPosition({ circle->X, circle->Y, 0 });
        imp->setRadius(circle->Radius);
        imp->SetBrush(DirectXRenderer::getInstance()->pBrush);
        if (imp == nullptr) {
            return;
        }
        transaction->AddNewlyObject(imp->getObjectId(), imp);
    }
    catch (const std::exception& e) {
        throw gcnew InvalidOperationException(gcnew String(e.what()));
    }
    catch (...) {
        throw gcnew InvalidOperationException("An unknown error occurred.");
    }
}

void TransactionWrapper::Abort()
{
    transaction->Abort();
}

void TransactionWrapper::Commit()
{
    transaction->Commit();
}

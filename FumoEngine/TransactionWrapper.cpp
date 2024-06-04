#include "pch.h"
#include "TransactionWrapper.h"
#include "DatabaseInterop.h"
#include "FmObject.h"

using namespace DatabaseServices;
using namespace msclr::interop;

TransactionWrapper::TransactionWrapper()
{
    if (DirectXRenderer::getInstance().CurDoc->TransactionManager == nullptr) {
        DirectXRenderer::getInstance().CurDoc->TransactionManager = std::make_unique<FmTransaction>(DirectXRenderer::getInstance().CurDoc);
    }
    transaction = DirectXRenderer::getInstance().CurDoc->TransactionManager.get();
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
    auto context = static_cast<ID3D11DeviceContext*>(DirectXRenderer::getInstance().deviceContext);
    auto renderTarget = static_cast<ID2D1HwndRenderTarget*>(DirectXRenderer::getInstance().pRenderTarget);
    transaction->StartTransaction(context, renderTarget);
}

void TransactionWrapper::AddNewlyObject(String^ id, IntPtr objPtr)
{
    std::string idStr = marshal_as<std::string>(id);
    auto obj = std::unique_ptr<FmObject>(static_cast<FmObject*>(objPtr.ToPointer()));
    transaction->AddNewlyObject(idStr, std::move(obj));
}

void TransactionWrapper::Abort()
{
    transaction->Abort();
}

void TransactionWrapper::Commit()
{
    transaction->Commit();
}

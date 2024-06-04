#pragma once
#include "Transaction.h"
#include "DirectXRenderer.h"

using namespace System;

public ref class TransactionWrapper
{
private:
	DatabaseServices::FmTransaction* transaction;
public:
    TransactionWrapper();
    TransactionWrapper(DatabaseServices::FmDatabasePtr parentDoc);
    ~TransactionWrapper();
    !TransactionWrapper();
    void StartTransaction();
    void AddNewlyObject(String^ id, IntPtr objPtr);
    void Abort();
    void Commit();
};


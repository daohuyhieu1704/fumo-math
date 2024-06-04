#pragma once
#include "Transaction.h"
#include "DirectXRenderer.h"
#include "DbObject.h"

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
    void AddNewlyObject(DbObject^ objPtr);
    void Abort();
    void Commit();
};


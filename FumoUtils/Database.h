#pragma once
#include "pch.h"
#include "DisposableWrapper.h"
#include "Transaction.h"
#include "DataTableRecord.h"
#include <fstream>

namespace DatabaseServices {

    class FmTransaction;

    typedef std::shared_ptr<class FmDatabase> FmDatabasePtr;
    typedef std::unique_ptr<FmTransaction> FmTransactionPtr;

    class FmDatabase : public DisposableWrapper
    {
    private:
        DataTableRecordPtr m_ObjectRecords;
    public:
        FmDatabase();
        void AppendObject(std::unique_ptr<FmObject> obj);
        void saveToJson(const std::string& filename);
        FmTransactionPtr TransactionManager;
    };
}
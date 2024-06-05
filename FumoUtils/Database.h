#pragma once
#include "pch.h"
#include "Transaction.h"
#include "DataTableRecord.h"
#include <fstream>

namespace DatabaseServices {

    class FmTransaction;

    typedef std::shared_ptr<class FmDatabase> FmDatabasePtr;
    typedef std::unique_ptr<FmTransaction> FmTransactionPtr;

    class FmDatabase : public FmObject
    {
    private:
        DataTableRecordPtr m_ObjectRecords;
    public:
        FmDatabase();
        void AppendObject(std::unique_ptr<FmObject> obj);
        void SaveToJson(const std::string& filename);
        FmTransactionPtr TransactionManager;
        FmObject* Clone() const override;
    };
}
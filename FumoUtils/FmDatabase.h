#pragma once
#include "pch.h"
#include "FmTransaction.h"
#include "DataTableRecord.h"
#include <fstream>

namespace DatabaseServices {

    class FmTransaction;

    typedef std::shared_ptr<class FmDatabase> FmDatabasePtr;
    typedef std::unique_ptr<FmTransaction> FmTransactionPtr;

    class FmDatabase : public FmObjectBase
    {
    private:
        DataTableRecordPtr m_ObjectRecords;
    public:
        FmDatabase();
        void AppendObject(std::unique_ptr<FmObjectBase> obj);
        void SaveToJson(const std::string& filename);
        FmTransactionPtr TransactionManager;
        FmObjectBase* Clone() const override;
    };
}
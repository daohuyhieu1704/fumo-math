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
        std::string m_name;
        DataTableRecordPtr m_ObjectRecords;
    public:
        FmDatabase();
#pragma region Properties
        std::string GetName() const;
        void SetName(const std::string& name);
#pragma endregion
        static FmDatabasePtr CreateObject();
        void AppendObject(std::unique_ptr<FmObjectBase> obj);
        void SaveToJson(const std::string& filename);
        FmTransactionPtr TransactionManager;
        FmObjectBase* Clone() const override;
    };
}
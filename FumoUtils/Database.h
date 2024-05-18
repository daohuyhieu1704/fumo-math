#pragma once
#include "pch.h"
#include "DisposableWrapper.h"
#include "Transaction.h"
#include "TableRecord.h"
#include <fstream>

namespace DatabaseServices {

    class FmDatabase : public DisposableWrapper
    {
        FmDatabase() : TransactionManager(std::make_unique<FmTransaction>()) {}

        void addTableRecord(TableRecordPtr record);

        void saveToJson(const std::string& filename);

        FmTransactionPtr TransactionManager;
    private:
        DataTableRecord records;

        std::vector<TableRecord*> getTableRecordPointers() const;
    };

    typedef std::unique_ptr<FmDatabase> FmDatabasePtr;
}
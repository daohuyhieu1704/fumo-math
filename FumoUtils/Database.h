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
        static FmDatabasePtr CreateObject();
        FmDatabase();
        void AppendObject(std::unique_ptr<FmObject> obj);
        void saveToJson(const std::string& filename);
        void Render(ID3D11DeviceContext* context, ID2D1HwndRenderTarget* renderTarget);
        FmTransactionPtr TransactionManager;
    };

    class DatabaseRegistrar {
    public:
        static void registerDatabase();
    };
}
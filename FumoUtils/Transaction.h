#pragma once
#include "DisposableWrapper.h"
#include "DataTableRecord.h"
#include "Database.h" 
#include <deque>

namespace DatabaseServices 
{
    class FmDatabase;
    typedef std::shared_ptr<FmDatabase> FmDatabasePtr;

    class FmTransaction : public DisposableWrapper
    {
    private:
        bool transactionActive;
        FmDatabasePtr m_Doc;
        std::map<std::string, FmObject*> newlyAddedObjects;
        bool isUndoRedoInProgress = false;
        std::deque<FmObject*> undoneObjects;
        ID3D11DeviceContext* context = nullptr;
        ID2D1HwndRenderTarget* renderTarget = nullptr;
    public:
        FmTransaction(FmDatabasePtr parentDoc) : transactionActive(false), m_Doc(parentDoc) {}
        void StartTransaction(ID3D11DeviceContext* context, ID2D1HwndRenderTarget* renderTarget);
        void AddNewlyObject(const std::string& id, FmObject* obj);
        void Abort();
        void Commit();
        void Undo();
        void Redo();
    };

    typedef std::shared_ptr<FmTransaction> FmTransactionPtr;
}
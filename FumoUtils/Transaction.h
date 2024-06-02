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
        std::map<std::string, std::unique_ptr<FmObject>> newlyAddedObjects;
        bool isUndoRedoInProgress = false;
        std::deque<std::unique_ptr<FmObject>> undoneObjects;
    public:
        FmTransaction(FmDatabasePtr parentDoc) : transactionActive(false), m_Doc(parentDoc) {}
        void StartTransaction();
        void AddNewlyObject(const std::string& id, std::unique_ptr<FmObject> obj);
        void Abort();
        void Commit();
        void Undo();
        void Redo();
    };

    typedef std::unique_ptr<FmTransaction> FmTransactionPtr;
}
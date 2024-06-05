#pragma once
#include "DataTableRecord.h"
#include "Database.h" 
#include <deque>

namespace DatabaseServices 
{
    class FmDatabase;
    typedef std::shared_ptr<FmDatabase> FmDatabasePtr;

    class FmTransaction : public FmObject
    {
    private:
        bool m_transactionActive;
        FmDatabasePtr m_Doc;
        std::map<std::string, std::unique_ptr<FmObject>> m_newlyAddedObjects;
        bool m_isUndoRedoInProgress = false;
        std::deque<std::unique_ptr<FmObject>> m_undoneObjects;
    public:
        FmTransaction(FmDatabasePtr parentDoc) : m_transactionActive(false), m_Doc(parentDoc) {}
        void StartTransaction();
        void AddNewlyObject(const std::string& id, std::unique_ptr<FmObject> obj);
        void Abort();
        void Commit();
        void Undo();
        void Redo();
        FmObject* Clone() const override;
        virtual ~FmTransaction() = default;
    };

    typedef std::unique_ptr<FmTransaction> FmTransactionPtr;
}
#pragma once
#include "DataTableRecord.h"
#include "FmDatabase.h" 
#include <deque>

namespace DatabaseServices 
{
    class FmTransaction;
    typedef std::shared_ptr<class FmDatabase> FmDatabasePtr;
    typedef std::shared_ptr<FmTransaction> FmTransactionPtr;

    class FmTransaction : public FmObjectBase
    {
    private:
        bool m_transactionActive;
        FmDatabasePtr m_Doc;
        std::map<std::string, std::shared_ptr<FmObjectBase>> m_newlyAddedObjects;
        bool m_isUndoRedoInProgress = false;
        std::deque<std::shared_ptr<FmObjectBase>> m_undoneObjects;
    public:
        FmTransaction(FmDatabasePtr parentDoc) : m_transactionActive(false), m_Doc(parentDoc) {}
        void StartTransaction();
        void AddNewlyObject(const std::string& id, std::shared_ptr<FmObjectBase> obj);
        void Abort();
        void Commit();
        void Undo();
        void Redo();
        FmObjectBase* Clone() const override;
        virtual ~FmTransaction() = default;
    };
}
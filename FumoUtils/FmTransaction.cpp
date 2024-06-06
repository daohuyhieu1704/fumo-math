#include "pch.h"
#include "FmDatabase.h"
#include "FmTransaction.h"
#include "FmDrawable.h"

namespace DatabaseServices {
    void FmTransaction::StartTransaction() {
        if (m_transactionActive) {
            throw std::runtime_error("Transaction is already active");
        }
        m_transactionActive = true;
        m_newlyAddedObjects.clear();
    }

    void FmTransaction::AddNewlyObject(const std::string& id, std::shared_ptr<FmObjectBase> obj) {
        if (!m_transactionActive) {
            throw std::runtime_error("No active transaction");
        }
        if (m_newlyAddedObjects.find(id) != m_newlyAddedObjects.end()) {
            throw std::runtime_error("Object with the given ID already exists");
        }
        m_newlyAddedObjects[id] = obj;
    }

    void FmTransaction::Abort() {
        if (!m_transactionActive) {
            throw std::runtime_error("No active transaction to abort");
        }
        m_newlyAddedObjects.clear();
        m_transactionActive = false;
    }

    void FmTransaction::Commit() {
        if (!m_transactionActive) {
            throw std::runtime_error("No active transaction to commit");
        }
        for (auto& pair : m_newlyAddedObjects) {
            m_Doc.get()->AppendObject(pair.second);
            FmDrawable* drawable = dynamic_cast<FmDrawable*>(pair.second.get());
            if (drawable != nullptr) {
            }
        }
        m_newlyAddedObjects.clear();
        m_transactionActive = false;
    }

    void FmTransaction::Undo() {
        if (m_newlyAddedObjects.empty() || m_isUndoRedoInProgress) {
            throw std::runtime_error("Nothing to undo");
        }
        m_isUndoRedoInProgress = true;

        auto lastAdded = m_newlyAddedObjects.rbegin();
        m_undoneObjects.push_back(lastAdded->second);
        m_newlyAddedObjects.erase(lastAdded->first);

        m_isUndoRedoInProgress = false;
    }

    void FmTransaction::Redo() {
        if (m_undoneObjects.empty() || m_isUndoRedoInProgress) {
            throw std::runtime_error("Nothing to redo");
        }
        m_isUndoRedoInProgress = true;

        auto lastUndone = std::move(m_undoneObjects.back());
        m_newlyAddedObjects[lastUndone->GetObjectId()] = std::move(lastUndone);
        m_undoneObjects.pop_back();

        m_isUndoRedoInProgress = false;
    }
    FmObjectBase* FmTransaction::Clone() const
    {
        return nullptr;
    }
}

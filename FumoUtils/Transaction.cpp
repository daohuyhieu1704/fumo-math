#include "pch.h"
#include "Database.h"
#include "Transaction.h"
#include "FmDrawable.h"

namespace DatabaseServices {
    void FmTransaction::StartTransaction() {
        if (transactionActive) {
            throw std::runtime_error("Transaction is already active");
        }
        transactionActive = true;
        newlyAddedObjects.clear();
    }

    void FmTransaction::AddNewlyObject(const std::string& id, std::unique_ptr<FmObject> obj) {
        if (!transactionActive) {
            throw std::runtime_error("No active transaction");
        }
        if (newlyAddedObjects.find(id) != newlyAddedObjects.end()) {
            throw std::runtime_error("Object with the given ID already exists");
        }
        newlyAddedObjects[id] = std::move(obj);
    }

    void FmTransaction::Abort() {
        if (!transactionActive) {
            throw std::runtime_error("No active transaction to abort");
        }
        newlyAddedObjects.clear();
        transactionActive = false;
    }

    void FmTransaction::Commit() {
        if (!transactionActive) {
            throw std::runtime_error("No active transaction to commit");
        }
        for (auto& pair : newlyAddedObjects) {
            m_Doc.get()->AppendObject(std::move(pair.second));
        }
        newlyAddedObjects.clear();
        transactionActive = false;
    }
}

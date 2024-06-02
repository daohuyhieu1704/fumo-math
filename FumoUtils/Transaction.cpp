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

    void FmTransaction::Undo() {
        if (newlyAddedObjects.empty() || isUndoRedoInProgress) {
            throw std::runtime_error("Nothing to undo");
        }
        isUndoRedoInProgress = true;

        // Remove the last added object
        auto lastAdded = newlyAddedObjects.rbegin(); // Get the last element in the map
        undoneObjects.push_back(std::move(lastAdded->second)); // Add it to undoneObjects (std::deque)
        newlyAddedObjects.erase(lastAdded->first);           // Remove it from the map
        // You don't need to pass this to the database now

        isUndoRedoInProgress = false;
    }

    void FmTransaction::Redo() {
        if (undoneObjects.empty() || isUndoRedoInProgress) {
            throw std::runtime_error("Nothing to redo");
        }
        isUndoRedoInProgress = true;

        // Take the ownership of the object from undoneObjects and reinsert it into newlyAddedObjects
        auto lastUndone = std::move(undoneObjects.back()); // Move the last undone object
        newlyAddedObjects[lastUndone->getObjectId()] = std::move(lastUndone);
        undoneObjects.pop_back();

        isUndoRedoInProgress = false;
    }
}

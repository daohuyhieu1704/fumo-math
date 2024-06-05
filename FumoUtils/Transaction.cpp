#include "pch.h"
#include "Database.h"
#include "Transaction.h"
#include "FmDrawable.h"

namespace DatabaseServices {
    void FmTransaction::StartTransaction(ID3D11DeviceContext* context, ID2D1HwndRenderTarget* renderTarget) {
        if (transactionActive) {
            throw std::runtime_error("Transaction is already active");
        }
        if (context == nullptr || renderTarget == nullptr) {
            return;
        }

        this->context = context;
        this->renderTarget = renderTarget;
        this->transactionActive = true;
        newlyAddedObjects.clear();
    }

    void FmTransaction::AddNewlyObject(const std::string& id, FmObject* obj) {
        //if (!transactionActive) {
        //    throw std::runtime_error("No active transaction");
        //}
        //if (newlyAddedObjects.find(id) != newlyAddedObjects.end()) {
        //    throw std::runtime_error("Object with the given ID already exists");
        //}
        newlyAddedObjects[id] = obj;
    }

    void FmTransaction::Abort() {
        if (!transactionActive) {
            throw std::runtime_error("No active transaction to abort");
        }
        newlyAddedObjects.clear();
        transactionActive = false;
    }

    void FmTransaction::Commit() {
        //if (!transactionActive) {
        //    throw std::runtime_error("No active transaction to commit");
        //}
        //for (auto& pair : newlyAddedObjects) {
        //    m_Doc.get()->AppendObject(pair.second);
        //}
        for (auto& pair : newlyAddedObjects) {
            static_cast<FmDrawable*>(pair.second)->draw(context, renderTarget);
        }
        //m_Doc.get()->Render(context, renderTarget);
        newlyAddedObjects.clear();
        //transactionActive = false;
    }

    void FmTransaction::Undo() {
        if (newlyAddedObjects.empty() || isUndoRedoInProgress) {
            throw std::runtime_error("Nothing to undo");
        }
        isUndoRedoInProgress = true;

        auto lastAdded = newlyAddedObjects.rbegin();
        undoneObjects.push_back(lastAdded->second);
        newlyAddedObjects.erase(lastAdded->first);

        isUndoRedoInProgress = false;
    }

    void FmTransaction::Redo() {
        if (undoneObjects.empty() || isUndoRedoInProgress) {
            throw std::runtime_error("Nothing to redo");
        }
        isUndoRedoInProgress = true;

        auto lastUndone = undoneObjects.back();
        newlyAddedObjects[lastUndone->getObjectId()] = lastUndone;
        undoneObjects.pop_back();

        isUndoRedoInProgress = false;
    }
}

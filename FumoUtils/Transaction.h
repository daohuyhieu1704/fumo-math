#pragma once
#include "DisposableWrapper.h"
#include "d3d11.h"
#include "TableRecord.h"

namespace DatabaseServices {
    class FmTransaction : public DisposableWrapper {
    public:
        FmTransaction() : transactionActive(false) {}
        void StartTransaction();
        void AddNewlyObject(const std::string& id, std::unique_ptr<FmObject> obj);
        void Abort();
        void Commit(ID3D11DeviceContext* context);
    private:
        bool transactionActive;
        std::unordered_map<std::string, std::unique_ptr<FmObject>> newlyAddedObjects;
    };

    typedef std::unique_ptr<FmTransaction> FmTransactionPtr;
}
#include "pch.h"
#include "FmDatabase.h"

namespace DatabaseServices {

    FmDatabase::FmDatabase()
        : TransactionManager(std::make_unique<FmTransaction>(FmDatabasePtr(this, [](FmDatabase*) {})))
        , m_ObjectRecords(std::make_unique<DataTableRecord>())
    {}

    void FmDatabase::AppendObject(std::unique_ptr<FmObjectBase> obj) {
        m_ObjectRecords->AddObject(std::move(obj));
    }

    void FmDatabase::SaveToJson(const std::string& filename) {
        nlohmann::json json;
        for (const auto& record : m_ObjectRecords->GetObjects()) {
            FmDbObject* dbObj = dynamic_cast<FmDbObject*>(record.get());
            if (dbObj == nullptr) {
                continue;
            }
            json.push_back(dbObj->ToJson());
        }
        std::ofstream file(filename);
        file << json.dump(4);
    }

    FmObjectBase* FmDatabase::Clone() const
    {
        return nullptr;
    }
}

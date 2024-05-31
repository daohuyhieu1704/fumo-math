#include "pch.h"
#include "Database.h"

namespace DatabaseServices {

    FmDatabase::FmDatabase()
        : TransactionManager(std::make_unique<FmTransaction>(FmDatabasePtr(this, [](FmDatabase*) {})))
        , m_ObjectRecords(std::make_unique<DataTableRecord>())
    {}

    void FmDatabase::AppendObject(std::unique_ptr<FmObject> obj) {
        m_ObjectRecords->addObject(std::move(obj));
    }

    void FmDatabase::saveToJson(const std::string& filename) {
        nlohmann::json json;
        for (const auto& record : m_ObjectRecords->GetObjects()) {
            FmDbObject* dbObj = dynamic_cast<FmDbObject*>(record.get());
            if (dbObj == nullptr) {
                continue;
            }
            json.push_back(dbObj->toJson());
        }
        std::ofstream file(filename);
        file << json.dump(4);
    }
}

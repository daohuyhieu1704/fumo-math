#include "pch.h"
#include "FmDatabase.h"

namespace DatabaseServices {
    std::string FmDatabase::GetName() const {
        return m_name;
    };

    void FmDatabase::SetName(const std::string& name) {
        m_name = name;
    };
    FmDatabase::FmDatabase()
        : TransactionManager(std::make_unique<FmTransaction>(FmDatabasePtr(this, [](FmDatabase*) {})))
        , m_ObjectRecords(std::make_unique<DataTableRecord>())
    {}

    FmDatabasePtr FmDatabase::CreateObject()
    {
        return std::make_shared<FmDatabase>();
    }

    void FmDatabase::AppendObject(std::shared_ptr<FmObjectBase> obj) {
        m_ObjectRecords->AddObject(obj);
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

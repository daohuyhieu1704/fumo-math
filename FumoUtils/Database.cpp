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

    /*void FmDatabase::saveToJson(const std::string& filename) {
        try {
            nlohmann::json json;
            for (const auto& record : records) {
                json.push_back(record->toJson());
            }
            std::ofstream file(filename);
            if (!file.is_open()) {
                throw std::runtime_error("Failed to open file for writing.");
            }
            file << json.dump(4);
            file.close();
        }
        catch (const std::exception& e) {
            std::cerr << "Error saving data to JSON file: " << e.what() << std::endl;
        }
    }*/

}

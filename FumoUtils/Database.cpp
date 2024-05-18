#include "pch.h"
#include "Database.h"

namespace DatabaseServices {

    void FmDatabase::addTableRecord(TableRecordPtr record)
    {
        records.push_back(std::move(record));
    }

    void FmDatabase::saveToJson(const std::string& filename) {
        nlohmann::json json;
        for (const auto& record : records) {
            json.push_back(record->toJson());
        }
        std::ofstream file(filename);
        file << json.dump(4);
    }

    std::vector<TableRecord*> FmDatabase::getTableRecordPointers() const
    {
        std::vector<TableRecord*> pointers;
        for (const auto& record : records) {
            pointers.push_back(record.get());
        }
        return pointers;
    }
}

#include "pch.h"
#include "DataTableRecord.h"

std::vector<FmObject*> DataTableRecord::GetObjects() const {
    std::vector<FmObject*> objects;
    for (const auto& obj : m_objects) {
        objects.push_back(obj.second);
    }
    return objects;
}

void DataTableRecord::addObject(FmObject* obj) {
    m_objects.insert({ obj->getObjectId(), obj });
}

bool DataTableRecord::GetObjectById(const std::string& id, FmObject* obj) {
    auto it = m_objects.find(id);
    if (it != m_objects.end()) {
        obj = it->second;
        return true;
    }
    return false;
}

nlohmann::json DataTableRecord::toJson() const {
    nlohmann::json jsonArray = nlohmann::json::array();
    for (const auto& obj : m_objects) {
        FmDbObject* dbObj = dynamic_cast<FmDbObject*>(obj.second);
        if (dbObj == nullptr) {
            continue;
        }
        jsonArray.push_back(dbObj->toJson());
    }
    return jsonArray;
}
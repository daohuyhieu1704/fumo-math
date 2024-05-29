#include "pch.h"
#include "DataTableRecord.h"

std::vector<std::shared_ptr<FmObject>> DataTableRecord::GetObjects() const {
    std::vector<std::shared_ptr<FmObject>> objects;
    for (const auto& obj : m_objects) {
        objects.push_back(std::shared_ptr<FmObject>(obj.second.get(), [](FmObject*) {}));
    }
    return objects;
}

void DataTableRecord::addObject(std::unique_ptr<FmObject> obj) {
    m_objects.insert({ obj->getObjectId(), std::move(obj) });
}

bool DataTableRecord::GetObjectById(const std::string& id, std::shared_ptr<FmObject>& obj) {
    auto it = m_objects.find(id);
    if (it != m_objects.end()) {
        obj = std::shared_ptr<FmObject>(it->second.get(), [](FmObject*) {});
        return true;
    }
    return false;
}

nlohmann::json DataTableRecord::toJson() const {
    nlohmann::json jsonArray = nlohmann::json::array();
    for (const auto& obj : m_objects) {
        FmDbObject* dbObj = dynamic_cast<FmDbObject*>(obj.second.get());
        if (dbObj == nullptr) {
            continue;
        }
        jsonArray.push_back(dbObj->toJson());
    }
    return jsonArray;
}
#include "pch.h"
#include "DataTableRecord.h"

std::vector<std::shared_ptr<FmObjectBase>> DataTableRecord::GetObjects() const
{
    std::vector<std::shared_ptr<FmObjectBase>> objects;
    for (const auto& pair : m_objects) {
        objects.push_back(std::shared_ptr<FmObjectBase>(pair.second.get()));
    }
    return objects;
}

void DataTableRecord::AddObject(std::unique_ptr<FmObjectBase> obj)
{
    std::string id = obj->GetObjectId();
    m_objects[id] = std::move(obj);
}

bool DataTableRecord::GetObjectById(const std::string& id, std::shared_ptr<FmObjectBase>& obj) {
    auto it = m_objects.find(id);
    if (it != m_objects.end()) {
        obj = std::shared_ptr<FmObjectBase>(it->second.get(), [](FmObjectBase*) {});
        return true;
    }
    return false;
}

nlohmann::json DataTableRecord::ToJson() const {
    nlohmann::json jsonArray = nlohmann::json::array();
    for (const auto& obj : m_objects) {
        FmDbObject* dbObj = dynamic_cast<FmDbObject*>(obj.second.get());
        if (dbObj == nullptr) {
            continue;
        }
        jsonArray.push_back(dbObj->ToJson());
    }
    return jsonArray;
}

FmObjectBase* DataTableRecord::Clone() const
{
    return nullptr;
}

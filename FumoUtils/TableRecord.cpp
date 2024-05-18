#include "pch.h"
#include "TableRecord.h"

void TableRecord::addObject(std::unique_ptr<FmDbObject> obj)
{
    objects.push_back(std::move(obj));
}

const std::vector<std::unique_ptr<FmDbObject>>& TableRecord::getObjects() const
{
    return objects;
}

nlohmann::json TableRecord::toJson() const
{
    nlohmann::json jsonArray = nlohmann::json::array();
    for (const auto& obj : objects) {
        jsonArray.push_back(obj->toJson());
    }
    return jsonArray;
}

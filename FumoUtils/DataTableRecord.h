#pragma once
#include "pch.h"
#include "FmDbObject.h"
#include <vector>

class DataTableRecord : public FmObject {
private:
    std::map<std::string, std::unique_ptr<FmObject>> m_objects;
public:
#pragma region Properties
    std::vector<std::shared_ptr<FmObject>> GetObjects() const;
#pragma endregion

    void AddObject(std::unique_ptr<FmObject> obj);

    bool GetObjectById(const std::string& id, std::shared_ptr<FmObject>& obj);

    nlohmann::json ToJson() const;
    FmObject* Clone() const override;
};

typedef std::unique_ptr<DataTableRecord> DataTableRecordPtr;
#pragma once
#include "pch.h"
#include "FmDbObject.h"
#include <vector>

class DataTableRecord : public FmObjectBase {
private:
    std::map<std::string, std::shared_ptr<FmObjectBase>> m_objects;
public:
#pragma region Properties
    std::vector<std::shared_ptr<FmObjectBase>> GetObjects() const;
#pragma endregion

    void AddObject(std::shared_ptr<FmObjectBase> obj);

    bool GetObjectById(const std::string& id, std::shared_ptr<FmObjectBase>& obj);

    nlohmann::json ToJson() const;
    FmObjectBase* Clone() const override;
};

typedef std::unique_ptr<DataTableRecord> DataTableRecordPtr;
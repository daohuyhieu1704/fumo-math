#pragma once
#include "pch.h"
#include "DisposableWrapper.h"
#include "FmDbObject.h"
#include <vector>

class DataTableRecord : public DisposableWrapper {
private:
    std::map<std::string, std::unique_ptr<FmObject>> m_objects;
public:
#pragma region Properties
    std::vector<std::shared_ptr<FmObject>> GetObjects() const;
#pragma endregion

    void addObject(std::unique_ptr<FmObject> obj);

    bool GetObjectById(const std::string& id, std::shared_ptr<FmObject>& obj);

    nlohmann::json toJson() const;
};

typedef std::unique_ptr<DataTableRecord> DataTableRecordPtr;
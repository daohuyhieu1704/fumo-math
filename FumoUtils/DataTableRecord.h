#pragma once
#include "pch.h"
#include "DisposableWrapper.h"
#include "FmDbObject.h"
#include <vector>

class DataTableRecord : public DisposableWrapper {
private:
    std::map<std::string, FmObject*> m_objects;
public:
#pragma region Properties
    std::vector<FmObject*> GetObjects() const;
#pragma endregion

    void addObject(FmObject* obj);

    bool GetObjectById(const std::string& id, FmObject* obj);

    nlohmann::json toJson() const;
};

typedef std::shared_ptr<DataTableRecord> DataTableRecordPtr;
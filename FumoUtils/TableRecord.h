#pragma once
#include "pch.h"
#include "DisposableWrapper.h"
#include "FmDbObject.h"
#include <vector>

class TableRecord : public DisposableWrapper {
public:
    void addObject(std::unique_ptr<FmDbObject> obj);

    const std::vector<std::unique_ptr<FmDbObject>>& getObjects() const;

    nlohmann::json toJson() const;

private:
    std::vector<std::unique_ptr<FmDbObject>> objects;
};

typedef std::unique_ptr<TableRecord> TableRecordPtr;
typedef std::vector<TableRecordPtr> DataTableRecord;

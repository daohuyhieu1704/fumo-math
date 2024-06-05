#pragma once
#include <FmDbObject.h>
public ref class DbObject
{
protected:
    FmDbObject* dbObject;

    DbObject(FmDbObject* obj) : dbObject(obj) {}

public:
    ~DbObject() {
        this->!DbObject();
    }

    !DbObject() {
        delete dbObject;
    }
};


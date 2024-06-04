#pragma once
#include <msclr/marshal_cppstd.h>
#include "Database.h"
#include "TransactionWrapper.h"

using namespace System;

public ref class DatabaseInterop {
private:
    DatabaseServices::FmDatabase* database;

public:
    DatabaseInterop();
    ~DatabaseInterop();
    property TransactionWrapper^ TransactionManager {
        TransactionWrapper^ get();
    }

    void SaveToJson(String^ filename);
};



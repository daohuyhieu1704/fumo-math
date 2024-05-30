#pragma once

#include <msclr/marshal_cppstd.h>
#include "Database.h"

using namespace System;

public ref class DatabaseInterop {
private:
    DatabaseServices::FmDatabase* database;

public:
    DatabaseInterop();
    ~DatabaseInterop();

    void SaveToJson(String^ filename);
};



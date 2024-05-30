#include "pch.h"
#include "DatabaseInterop.h"

using namespace msclr::interop;

DatabaseInterop::DatabaseInterop() {
    database = new DatabaseServices::FmDatabase();
}

DatabaseInterop::~DatabaseInterop() {
    delete database;
}

void DatabaseInterop::SaveToJson(String^ filename) {
    std::string nativeFilename = marshal_as<std::string>(filename);
    database->saveToJson(nativeFilename);
}
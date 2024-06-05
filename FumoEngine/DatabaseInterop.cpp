#include "pch.h"
#include "DatabaseInterop.h"
#include "DirectXRenderer.h"
#include "TransactionWrapper.h"

using namespace msclr::interop;

DatabaseInterop::DatabaseInterop() {
    DatabaseServices::FmDatabasePtr CurDoc = DirectXRenderer::getInstance()->CurDoc;
    std::vector<DatabaseServices::FmDatabasePtr> Dbs = DirectXRenderer::getInstance()->Dbs;
    if (CurDoc == nullptr || Dbs.size() == 0) {
        Dbs.push_back(DatabaseServices::FmDatabase::CreateObject());
    }
    CurDoc = DirectXRenderer::getInstance()->Dbs.back();
    database = CurDoc.get();
}

DatabaseInterop::~DatabaseInterop() {
    delete database;
}

void DatabaseInterop::SaveToJson(String^ filename) {
    std::string nativeFilename = marshal_as<std::string>(filename);
    database->saveToJson(nativeFilename);
}

TransactionWrapper^ DatabaseInterop::TransactionManager::get()
{
    return gcnew TransactionWrapper();
}

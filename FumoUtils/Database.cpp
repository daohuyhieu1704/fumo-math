#include "pch.h"
#include "Database.h"
#include "FmObject.h"

namespace DatabaseServices {
    static struct DatabaseAutoRegistrar {
        DatabaseAutoRegistrar() {
            DatabaseRegistrar::registerDatabase();
        }
    } databaseAutoRegistrar;

    FmDatabasePtr FmDatabase::CreateObject() {
        std::shared_ptr<DisposableWrapper> obj = ObjectFactory::instance().createObject("Database");
        FmDatabasePtr dbPtr = std::dynamic_pointer_cast<FmDatabase>(std::move(obj));

        return dbPtr;
    }

    FmDatabase::FmDatabase()
        : TransactionManager(std::make_unique<FmTransaction>(FmDatabasePtr(this, [](FmDatabase*) {})))
        , m_ObjectRecords(std::make_unique<DataTableRecord>())
    {}

    void FmDatabase::AppendObject(std::unique_ptr<FmObject> obj) {
        m_ObjectRecords->addObject(std::move(obj));
    }

    void FmDatabase::saveToJson(const std::string& filename) {
        nlohmann::json json;
        for (const auto& record : m_ObjectRecords->GetObjects()) {
            FmDbObject* dbObj = dynamic_cast<FmDbObject*>(record.get());
            if (dbObj == nullptr) {
                continue;
            }
            json.push_back(dbObj->toJson());
        }
        std::ofstream file(filename);
        file << json.dump(4);
    }
    void FmDatabase::Render(ID3D11DeviceContext* context, ID2D1HwndRenderTarget* renderTarget)
    {
        if (m_ObjectRecords->GetObjects().size() == 0) {
            return;
        }

        for (const auto& obj : m_ObjectRecords->GetObjects()) {
            FmDrawable* drawable = dynamic_cast<FmDrawable*>(obj.get());
            if (drawable == nullptr) {
                continue;
            }

            drawable->draw(context, renderTarget);
        }
    }
    void DatabaseRegistrar::registerDatabase()
    {
        ObjectFactory::instance().registerType<DatabaseServices::FmDatabase>("Database");
    }
}

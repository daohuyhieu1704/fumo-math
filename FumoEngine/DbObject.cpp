#include "pch.h"
#include "DbObject.h"

System::String^ FumoWrapper::DbObject::Json::get()
{
    nlohmann::json json = GetImpObj()->ToJson();
    std::string jsonString = json.dump();
    return gcnew System::String(jsonString.c_str());
}

FmDbObject* FumoWrapper::DbObject::GetImpObj()
{
    void* obj = DisposableWrapper::GetImpObj();
    FmObjectBase* objBase = static_cast<FmObjectBase*>(obj);
    FmDrawable* objDrawable = static_cast<FmDrawable*>(objBase);
    FmDbObject* objDb = static_cast<FmDbObject*>(objDrawable);
    return objDb;
}
#include "pch.h"
#include "DbObject.h"

System::String^ FumoWrapper::DbObject::Json::get()
{
    nlohmann::json json = GetNativePointer()->ToJson();
    std::string jsonString = json.dump();
    return gcnew System::String(jsonString.c_str());
}

FmDbObject* FumoWrapper::DbObject::GetNativePointer()
{
    return static_cast<FmDbObject*>(DisposableWrapper<FmObjectBase>::GetNativePointer());
}
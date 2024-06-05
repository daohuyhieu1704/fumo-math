#pragma once
#include "ObjectBase.h"
#include "DataTableRecord.h"

using namespace System::Collections::Generic;

namespace FumoWrapper {
    namespace DbServices {
        public ref class Dtr : public ObjectBase
        {
        public:
            Dtr() : ObjectBase(new DataTableRecord()) {}

            void AddObject(ObjectBase^ obj)
            {
                GetNativePointer()->AddObject(std::unique_ptr<FmObjectBase>(obj->GetNativePointer()));
            }

            bool GetObjectById(System::String^ id, ObjectBase^% obj)
            {
                std::string nativeId = msclr::interop::marshal_as<std::string>(id);
                std::shared_ptr<FmObjectBase> nativeObj;
                bool result = GetNativePointer()->GetObjectById(nativeId, nativeObj);
                if (result)
                {
                    obj = gcnew ObjectBase(nativeObj.get());
                }
                return result;
            }

            property List<ObjectBase^>^ Objects
            {
                List<ObjectBase^>^ get()
                {
                    auto objects = GetNativePointer()->GetObjects();
                    List<ObjectBase^>^ list = gcnew List<ObjectBase^>();
                    for (const auto& obj : objects)
                    {
                        list->Add(gcnew ObjectBase(obj.get()));
                    }
                    return list;
                }
            }

            property System::String^ Json
            {
                System::String^ get()
                {
                    nlohmann::json json = GetNativePointer()->ToJson();
                    std::string jsonString = json.dump();
                    return gcnew System::String(jsonString.c_str());
                }
            }

        private:
            DataTableRecord* GetNativePointer()
            {
                return static_cast<DataTableRecord*>(DisposableWrapper<FmObjectBase>::GetNativePointer());
            }
        };
    }
}

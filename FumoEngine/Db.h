#pragma once
#include "ObjectBase.h"
#include "FmDatabase.h"
#include "Trans.h"

namespace FumoWrapper {
    namespace DbServices {
        public ref class Db : public ObjectBase
        {
        public:
            Db() : ObjectBase(new DatabaseServices::FmDatabase()) {}

            void AppendObject(ObjectBase^ obj)
            {
                GetNativePointer()->AppendObject(std::unique_ptr<FmObjectBase>(obj->GetNativePointer()));
            }

            void SaveToJson(System::String^ filename)
            {
                std::string nativeFilename = msclr::interop::marshal_as<std::string>(filename);
                GetNativePointer()->SaveToJson(nativeFilename);
            }

            Trans^ GetTransactionManager()
            {
                return gcnew Trans(GetNativePointer()->TransactionManager.get());
            }

        private:
            DatabaseServices::FmDatabase* GetNativePointer()
            {
                return static_cast<DatabaseServices::FmDatabase*>(DisposableWrapper<FmObjectBase>::GetNativePointer());
            }
        };
    }
}

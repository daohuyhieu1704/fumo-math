#pragma once
#include "ObjectBase.h"
#include "FmDatabase.h"
#include "Trans.h"

namespace FumoWrapper {
    namespace DbServices {
        public ref class Db : public ObjectBase
        {
        public:
            Db(IntPtr unmanagedObjPtr, bool autoDelete) : ObjectBase(System::IntPtr(unmanagedObjPtr), autoDelete) {}
            Db() : ObjectBase(System::IntPtr(new DatabaseServices::FmDatabase()), true) {}

            void AppendObject(ObjectBase^ obj)
            {
                GetImpObj()->AppendObject(std::unique_ptr<FmObjectBase>(obj->GetImpObj()));
            }

            void SaveToJson(System::String^ filename)
            {
                std::string nativeFilename = msclr::interop::marshal_as<std::string>(filename);
                GetImpObj()->SaveToJson(nativeFilename);
            }

            Trans^ GetTransactionManager()
            {
                return gcnew Trans(System::IntPtr(GetImpObj()->TransactionManager.get()), true);
            }

        private:
            DatabaseServices::FmDatabase* GetImpObj()
            {
                return static_cast<DatabaseServices::FmDatabase*>(DisposableWrapper::GetImpObj());
            }
        };
    }
}

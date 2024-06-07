#pragma once
#include "ObjectBase.h"
#include "FmTransaction.h"
#include "FmRenderer.h"

namespace FumoWrapper {
    namespace DbServices {
        public ref class Trans : public ObjectBase
        {
        public:
            Trans() : ObjectBase(FmRenderer::Instance->GetNativePointer()->CurDoc()->TransactionManager.get()) {}
            Trans(DatabaseServices::FmTransaction* ptr) : ObjectBase(ptr) {}

            void StartTransaction()
            {
                GetNativePointer()->StartTransaction();
            }

            void AddNewlyObject(System::String^ id, ObjectBase^ obj)
            {
                std::string nativeId = msclr::interop::marshal_as<std::string>(id);
                GetNativePointer()->AddNewlyObject(nativeId, std::shared_ptr<FmObjectBase>(obj->GetNativePointer()));
            }

            void Abort()
            {
                GetNativePointer()->Abort();
            }

            void Commit()
            {
                GetNativePointer()->Commit();
            }

            void Undo()
            {
                GetNativePointer()->Undo();
            }

            void Redo()
            {
                GetNativePointer()->Redo();
            }

        private:
            DatabaseServices::FmTransaction* GetNativePointer()
            {
                return static_cast<DatabaseServices::FmTransaction*>(DisposableWrapper<FmObjectBase>::GetNativePointer());
            }
        };
    }
}

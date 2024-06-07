#pragma once
#include "ObjectBase.h"
#include "FmTransaction.h"
#include "FmRenderer.h"

namespace FumoWrapper {
    namespace DbServices {
        public ref class Trans : public ObjectBase
        {
        public:
            Trans(IntPtr unmanagedObjPtr, bool autoDelete) : ObjectBase(System::IntPtr(unmanagedObjPtr), autoDelete) {}
            Trans() : ObjectBase(System::IntPtr(FmRenderer::Instance->GetImpObj()->CurDoc()->TransactionManager.get()), true) {}

            void StartTransaction()
            {
                GetImpObj()->StartTransaction(FmRenderer::Instance->GetImpObj()->pRenderTarget);
            }

            void AddNewlyObject(ObjectBase^ obj)
            {
                GetImpObj()->AddNewlyObject(std::shared_ptr<FmObjectBase>(obj->GetImpObj()));
            }

            void Abort()
            {
                GetImpObj()->Abort();
            }

            void Commit()
            {
                GetImpObj()->Commit();
            }

            void Undo()
            {
                GetImpObj()->Undo();
            }

            void Redo()
            {
                GetImpObj()->Redo();
            }

        private:
            DatabaseServices::FmTransaction* GetImpObj()
            {
                void* obj = DisposableWrapper::GetImpObj();
                return static_cast<DatabaseServices::FmTransaction*>(obj);
            }
        };
    }
}

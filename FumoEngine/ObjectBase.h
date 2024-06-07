#pragma once
#include "DisposableWrapper.h"
#include <FmObjectBase.h>
#include <msclr/marshal_cppstd.h>

namespace FumoWrapper {
    public ref class ObjectBase : public DisposableWrapper
	{
    public:
        ObjectBase(IntPtr unmanagedObjPtr, bool autoDelete) : DisposableWrapper(System::IntPtr(unmanagedObjPtr), autoDelete)
        {
        }

        static System::String^ GenerateId();
        property System::String^ ObjectId
        {
            System::String^ get();
        }
        ~ObjectBase() {};
        virtual ObjectBase^ Clone();

        FmObjectBase* GetImpObj()
        {
            void* obj = DisposableWrapper::GetImpObj();
            return static_cast<FmObjectBase*>(obj);
        }
	};
}

#pragma once
#include "DisposableWrapper.h"
#include <FmObjectBase.h>
#include <msclr/marshal_cppstd.h>

namespace FumoWrapper {
    public ref class ObjectBase : public DisposableWrapper<FmObjectBase>
	{
    public:
        ObjectBase() : DisposableWrapper(nullptr) {}

        ObjectBase(FmObjectBase* ptr) : DisposableWrapper(ptr) {}

        property System::String^ ObjectId
        {
            System::String^ get();
            void set(System::String^ value);
        }

        ObjectBase^ Clone();
	};

    public ref class ObjectFactory
    {
    public:
        static ObjectFactory^ Instance = gcnew ObjectFactory();

        template<typename T>
        void RegisterType(System::String^ type)
        {
            std::string typeStr = msclr::interop::marshal_as<std::string>(type);
            ObjectFactory::Instance().RegisterType<T>(typeStr);
        }

        ObjectBase^ CreateObject(System::String^ type)
        {
            std::string typeStr = msclr::interop::marshal_as<std::string>(type);
            std::unique_ptr<FmObjectBase> obj = ObjectBaseFactory::Instance().CreateObject(typeStr);
            if (obj != nullptr) {
                return gcnew ObjectBase(obj.release());
            }
            return nullptr;
        }
    };
}

#include "pch.h"
#include "ObjectBase.h"

namespace FumoWrapper
{
    System::String^ ObjectBase::ObjectId::get()
    {
        return gcnew System::String(GetNativePointer()->GetObjectId().c_str());
    }

    void ObjectBase::ObjectId::set(System::String^ value)
    {
        std::string objectId = msclr::interop::marshal_as<std::string>(value);
        GetNativePointer()->SetObjectId(objectId);
    }

    ObjectBase^ ObjectBase::Clone()
    {
        return gcnew ObjectBase(GetNativePointer()->Clone());
    }
}
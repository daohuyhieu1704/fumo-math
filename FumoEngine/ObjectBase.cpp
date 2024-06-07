#include "pch.h"
#include "ObjectBase.h"

namespace FumoWrapper
{
    System::String^ ObjectBase::ObjectId::get()
    {
        return gcnew System::String(GetImpObj()->GetObjectId().c_str());
    }
    ObjectBase^ ObjectBase::Clone()
    {
        return gcnew ObjectBase(System::IntPtr(GetImpObj()->Clone()), true);
    }
    String^ ObjectBase::GenerateId()
    {
        return gcnew System::String(FmObjectBase::GenerateShortId().c_str());
    }
}
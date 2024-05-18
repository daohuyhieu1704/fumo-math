#include "pch.h"
#include "DisposableWrapper.h"

DisposableWrapper::~DisposableWrapper()
{
    deleteUnmanagedObject();
}

DisposableWrapper& DisposableWrapper::operator=(DisposableWrapper&& other) noexcept
{
    if (this != &other)
    {
        deleteUnmanagedObject();
        managedPtr = other.managedPtr;
        other.managedPtr = nullptr;
    }
    return *this;
}

void DisposableWrapper::deleteUnmanagedObject()
{
    if (managedPtr) {
        managedPtr = nullptr;
    }
}
#pragma once
class DisposableWrapper
{
public:
    DisposableWrapper() : managedPtr(nullptr) {}

    virtual ~DisposableWrapper();

    DisposableWrapper(const DisposableWrapper&) = delete;

    DisposableWrapper& operator=(const DisposableWrapper&) = delete;

    DisposableWrapper(DisposableWrapper&& other) noexcept : managedPtr(other.managedPtr) {
        other.managedPtr = nullptr;
    }

    DisposableWrapper& operator=(DisposableWrapper&& other) noexcept;

protected:
    void* managedPtr;
    virtual void deleteUnmanagedObject();
};


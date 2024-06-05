#pragma once
#include <unordered_map>
#include <functional>
#include <memory>
#include <string>

class DisposableWrapper
{
public:
    static std::string generate_short_id();
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


typedef std::shared_ptr<DisposableWrapper> FmObjectPtr;

class ObjectFactory {
public:
    using CreatorFunc = std::function<std::shared_ptr<DisposableWrapper>()>;

    static ObjectFactory& instance();

    template<typename T>
    void registerType(const std::string& type);

    std::shared_ptr<DisposableWrapper> createObject(const std::string& type) const;

private:
    std::unordered_map<std::string, CreatorFunc> creators;
    ObjectFactory() = default;
    ObjectFactory(const ObjectFactory&) = delete;
    ObjectFactory& operator=(const ObjectFactory&) = delete;
};

template<typename T>
inline void ObjectFactory::registerType(const std::string& type) {
    creators[type] = []() -> std::shared_ptr<DisposableWrapper> {
        return std::make_shared<T>();
        };
}

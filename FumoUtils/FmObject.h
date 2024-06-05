#pragma once
#include <unordered_map>
#include <functional>
#include <memory>
#include <string>

class FmObject {
private:
    std::string m_objectId;
public:
    FmObject() {}
    virtual ~FmObject() {}

#pragma region Properties
    std::string GetObjectId() const;
    void SetObjectId(const std::string& objectId);
#pragma endregion
    virtual FmObject* Clone() const = 0;
};

typedef std::unique_ptr<FmObject> FmObjectPtr;

class ObjectFactory {
public:
    using CreatorFunc = std::function<std::unique_ptr<FmObject>()>;

    static ObjectFactory& Instance();

    template<typename T>
    void RegisterType(const std::string& type);

    std::unique_ptr<FmObject> CreateObject(const std::string& type) const;

private:
    std::unordered_map<std::string, CreatorFunc> creators;
    ObjectFactory() = default;
    ObjectFactory(const ObjectFactory&) = delete;
    ObjectFactory& operator=(const ObjectFactory&) = delete;
};

template<typename T>
inline void ObjectFactory::RegisterType(const std::string& type) {
    creators[type] = []() -> std::unique_ptr<FmObject> {
        return std::make_unique<T>();
        };
}

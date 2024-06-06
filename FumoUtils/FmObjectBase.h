#pragma once
#include <unordered_map>
#include <functional>
#include <memory>
#include <string>

class FmObjectBase {
private:
    std::string m_objectId;
public:
    FmObjectBase() : m_objectId(GenerateShortId()) {}
    virtual ~FmObjectBase() {}

#pragma region Properties
    std::string GetObjectId() const;
    void SetObjectId(const std::string& objectId);
#pragma endregion
    static std::string GenerateShortId();
    virtual FmObjectBase* Clone() const = 0;
};

typedef std::unique_ptr<FmObjectBase> FmObjectBasePtr;

class ObjectBaseFactory {
public:
    using CreatorFunc = std::function<std::unique_ptr<FmObjectBase>()>;

    static ObjectBaseFactory& Instance();

    template<typename T>
    void RegisterType(const std::string& type);

    std::unique_ptr<FmObjectBase> CreateObject(const std::string& type) const;

private:
    std::unordered_map<std::string, CreatorFunc> creators;
    ObjectBaseFactory() = default;
    ObjectBaseFactory(const ObjectBaseFactory&) = delete;
    ObjectBaseFactory& operator=(const ObjectBaseFactory&) = delete;
};

template<typename T>
inline void ObjectBaseFactory::RegisterType(const std::string& type) {
    creators[type] = []() -> std::unique_ptr<FmObjectBase> {
        return std::make_unique<T>();
        };
}

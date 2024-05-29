#pragma once
#include "pch.h"
#include "DisposableWrapper.h"
#include "Geometry.h"
#include <unordered_map>
#include <functional>
#include <memory>
#include <string>

class FmObject : public DisposableWrapper
{
private:
    std::string m_objectId;
public:

#pragma region Properties
    std::string getObjectId() const;
	void setObjectId(const std::string& objectId);
#pragma endregion


    FmObject(){}

    virtual ~FmObject() {}

    static FmObject* create(void* unmanagedPointer);

    virtual FmObject* clone() const = 0;

    virtual void copyFrom(const FmObject& source) = 0;
};

typedef std::unique_ptr<FmObject> FmObjectPtr;

class ObjectFactory {
public:
    using CreatorFunc = std::function<std::unique_ptr<FmObject>()>;

    static ObjectFactory& instance();

    template<typename T>
    void registerType(const std::string& type);

    std::unique_ptr<FmObject> createObject(const std::string& type) const;

private:
    std::unordered_map<std::string, CreatorFunc> creators;
    ObjectFactory() = default;
    ObjectFactory(const ObjectFactory&) = delete;
    ObjectFactory& operator=(const ObjectFactory&) = delete;
};

template<typename T>
inline void ObjectFactory::registerType(const std::string& type)
{
    creators[type] = []() -> std::unique_ptr<FmObject> {
        return std::make_unique<T>();
        };
}

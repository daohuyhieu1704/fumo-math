#pragma once
#include "DisposableWrapper.h"
#include <string>

class FmObject : public DisposableWrapper {
private:
    std::string m_objectId;
public:
    FmObject() {}
    virtual ~FmObject() {}

#pragma region Properties
    std::string getObjectId() const;
    void setObjectId(const std::string& objectId);
#pragma endregion

    static FmObject* create(void* unmanagedPointer);

    virtual FmObject* clone() const = 0;
    virtual void copyFrom(const FmObject& source) = 0;
};
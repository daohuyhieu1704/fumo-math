#include "pch.h"
#include "DisposableWrapper.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <random>
#include <ctime>
#include <string>

std::string DisposableWrapper::generate_short_id() {
    std::time_t t = std::time(nullptr);

    std::mt19937 rng(static_cast<unsigned int>(t));
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 15);

    std::stringstream ss;
    ss << std::hex << std::setw(8) << std::setfill('0') << (t & 0xFFFFFFF);

    for (int i = 0; i < 2; ++i) {
        ss << std::hex << dist(rng);
    }

    return ss.str().substr(0, 8);
}

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


ObjectFactory& ObjectFactory::instance()
{
    static ObjectFactory factory;
    return factory;
}

std::shared_ptr<DisposableWrapper> ObjectFactory::createObject(const std::string& type) const
{
    auto it = creators.find(type);
    if (it != creators.end()) {
        return it->second();
    }
    return nullptr;
}

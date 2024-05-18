#include "pch.h"
#include "FmDbObject.h"

nlohmann::json FmDbObject::toJson() const
{
    return 
    {
        {"position", {position.x, position.y}},
        {"rotation", rotation},
    };
}
#include "pch.h"
#include "FmDbObject.h"

nlohmann::json FmDbObject::ToJson() const
{
    return 
    {
        {"position", {m_position.x, m_position.y}},
        {"rotation", m_rotation},
    };
}
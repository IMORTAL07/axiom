#pragma once

#include "axiom/ecs/Component.h"

namespace axiom
{
    inline ComponentType getNextComponentType()
    {
        static ComponentType lastType = 0;
        return lastType++;
    }

    template<typename T>
    ComponentType getComponentType()
    {
        static ComponentType type = getNextComponentType();
        return type;
    }
}

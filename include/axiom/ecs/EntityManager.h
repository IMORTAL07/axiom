#pragma once

#include "axiom/ecs/Entity.h"
#include <queue>

namespace axiom
{
    class EntityManager
    {
    public:
        Entity createEntity();
        void destroyEntity(Entity entity);

    private:
        Entity m_nextEntity {1};
        std::queue<Entity> m_freeEntities;
    };
}

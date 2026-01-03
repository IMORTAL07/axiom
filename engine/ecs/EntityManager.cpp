#include "axiom/ecs/EntityManager.h"

namespace axiom
{
    Entity EntityManager::createEntity()
    {
        if (!m_freeEntities.empty())
        {
            Entity e = m_freeEntities.front();
            m_freeEntities.pop();
            return e;
        }

        return m_nextEntity++;
    }

    void EntityManager::destroyEntity(Entity entity)
    {
        m_freeEntities.push(entity);
    }
}

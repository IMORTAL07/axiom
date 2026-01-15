#pragma once

#include "axiom/ecs/Entity.h"
#include <unordered_map>

namespace axiom
{
    template<typename T>
    class ComponentStorage
    {
    public:
        void add(Entity entity, const T& component)
        {
            m_components[entity] = component;
        }

        void remove(Entity entity)
        {
            m_components.erase(entity);
        }

        bool has(Entity entity) const
        {
            return m_components.find(entity) != m_components.end();
        }

        T& get(Entity entity)
        {
            return m_components.at(entity);
        }

    private:
        std::unordered_map<Entity, T> m_components;
    };
}

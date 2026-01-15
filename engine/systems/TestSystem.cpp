#include "axiom/systems/TestSystem.h"
#include "axiom/ecs/EntityManager.h"
#include "axiom/ecs/ComponentStorage.h"
#include "axiom/ecs/Transform.h"

#include <iostream>

namespace axiom
{
    void TestSystem::onInitialize()
    {
        std::cout << "[TestSystem] Initialized\n";

        EntityManager em;
        Entity entity = em.createEntity();

        ComponentStorage<Transform> transforms;

        transforms.add(entity, {10.0f, 20.0f});

        if (transforms.has(entity))
        {
            auto& t = transforms.get(entity);
            std::cout << "[TestSystem] Entity "
                      << entity
                      << " Transform = ("
                      << t.x << ", " << t.y << ")\n";
        }
    }

    void TestSystem::onUpdate(double)
    {
    }

    void TestSystem::onShutdown()
    {
        std::cout << "[TestSystem] Shutdown\n";
    }
}

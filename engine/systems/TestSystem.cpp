#include "axiom/systems/TestSystem.h"
#include "axiom/ecs/EntityManager.h"
#include <iostream>

namespace axiom
{
    void TestSystem::onInitialize()
    {
        std::cout << "[TestSystem] Initialized\n";

        EntityManager em;
        Entity e1 = em.createEntity();
        Entity e2 = em.createEntity();

        std::cout << "[TestSystem] Created entities: "
                  << e1 << ", " << e2 << "\n";

        em.destroyEntity(e1);
        Entity e3 = em.createEntity();

        std::cout << "[TestSystem] Reused entity: "
                  << e3 << "\n";
    }

    void TestSystem::onUpdate(double)
    {
    }

    void TestSystem::onShutdown()
    {
        std::cout << "[TestSystem] Shutdown\n";
    }
}

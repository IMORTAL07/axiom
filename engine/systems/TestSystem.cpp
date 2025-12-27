#include "axiom/systems/TestSystem.h"
#include <iostream>

namespace axiom
{
    void TestSystem::onInitialize()
    {
        std::cout << "[TestSystem] Initialized\n";
    }

    void TestSystem::onUpdate(double deltaTime)
    {
        static double accumulator = 0.0;
        accumulator += deltaTime;

        if (accumulator >= 1.0)
        {
            std::cout << "[TestSystem] Updating...\n";
            accumulator = 0.0;
        }
    }

    void TestSystem::onShutdown()
    {
        std::cout << "[TestSystem] Shutdown\n";
    }
}

#include "axiom/Engine.h"
#include "axiom/System.h"

#include <iostream>
#include <chrono>

namespace axiom
{
    Engine::Engine()
        : m_running(false)
    {
    }

    void Engine::addSystem(std::unique_ptr<System> system)
    {
        m_systems.push_back(std::move(system));
    }

    void Engine::initialize()
    {
        std::cout << "Axiom Engine initializing...\n";

        for (auto& system : m_systems)
        {
            system->onInitialize();
        }

        m_running = true;
    }

    void Engine::run()
    {
        initialize();

        using clock = std::chrono::high_resolution_clock;
        auto lastTime = clock::now();

        while (m_running)
        {
            auto currentTime = clock::now();
            std::chrono::duration<double> delta = currentTime - lastTime;
            lastTime = currentTime;

            update(delta.count());
        }

        shutdown();
    }

    void Engine::update(double deltaTime)
    {
        for (auto& system : m_systems)
        {
            system->onUpdate(deltaTime);
        }
    }

    void Engine::shutdown()
    {
        for (auto& system : m_systems)
        {
            system->onShutdown();
        }

        std::cout << "Axiom Engine shutting down...\n";
    }

    void Engine::stop()
    {
        m_running = false;
    }
}

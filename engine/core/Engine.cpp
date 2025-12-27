#include "axiom/Engine.h"
#include <iostream>
#include <chrono>

namespace axiom
{
    Engine::Engine()
        : m_running(false)
    {
    }

    void Engine::initialize()
    {
        std::cout << "Axiom Engine initializing...\n";
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
        // TEMP: print delta time once per second approx
        static double accumulator = 0.0;
        accumulator += deltaTime;

        if (accumulator >= 1.0)
        {
            std::cout << "Engine running... dt = " << deltaTime << " seconds\n";
            accumulator = 0.0;
        }
    }

    void Engine::shutdown()
    {
        std::cout << "Axiom Engine shutting down...\n";
    }

    void Engine::stop()
    {
        m_running = false;
    }
}

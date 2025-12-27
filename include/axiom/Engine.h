#pragma once

#include <vector>
#include <memory>

namespace axiom
{
    class System;

    class Engine
    {
    public:
        Engine();

        void run();
        void stop();

        void addSystem(std::unique_ptr<System> system);

    private:
        void initialize();
        void update(double deltaTime);
        void shutdown();

        bool m_running;
        std::vector<std::unique_ptr<System>> m_systems;
    };
}

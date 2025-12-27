#pragma once

namespace axiom
{
    class Engine
    {
    public:
        Engine();

        void run();
        void stop();

    private:
        void initialize();
        void update(double deltaTime);
        void shutdown();

        bool m_running;
    };
}

#pragma once

namespace axiom
{
    class System
    {
    public:
        virtual ~System() = default;

        virtual void onInitialize() {}
        virtual void onUpdate(double deltaTime) {}
        virtual void onShutdown() {}
    };
}

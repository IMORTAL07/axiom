#pragma once

#include "axiom/System.h"

namespace axiom
{
    class TestSystem : public System
    {
    public:
        void onInitialize() override;
        void onUpdate(double deltaTime) override;
        void onShutdown() override;
    };
}

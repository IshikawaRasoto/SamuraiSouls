#pragma once

#include "Entities/Objects/Object.hpp"
#include "Type.hpp"

#define MINIGROUND_WIDTH 32
#define MINIGROUND_HEIGHT 111

#define MINIGROUND_DIR "./Textures/Scenario/Cemetery/MiniGround.png"

namespace Entities{
    namespace Objects{
        namespace Surfaces{
            class MiniGround : public Object{
            private:
                void initializeSprite();
            public:
                MiniGround(sf::Vector2f position);
                ~MiniGround();

                void update(float dt);

                void save();
            };
        }
    }
}
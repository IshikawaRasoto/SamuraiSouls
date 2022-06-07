#pragma once

#include "Entities/Objects/Object.hpp"
#include "Type.hpp"

#define BARREL_WIDTH 24
#define BARREL_HEIGHT 30

namespace Entities{
    namespace Objects{ 
        namespace Obstacles{
            class Barrel : public Object{
            
            private:
                void initializeSprite();

            public:
                Barrel(sf::Vector2f position);
                ~Barrel();

                void update(float dt);
                void save();
                void render();
            };
        }
    }
}
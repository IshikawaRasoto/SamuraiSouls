
#pragma once

#include "Entities/Objects/Object.hpp"
#include "Type.hpp"
#include <SFML/System/Vector2.hpp>

#define PLATFORM_WIDTH 2000
#define PLATFORM_HEIGHT 100

namespace Entities{
    namespace Objects{
        namespace Surfaces{
            class Platform : public Object{
            private:
                void initializeSprite();
            public:
                Platform(sf::Vector2f position);
                ~Platform();

                void update(float dt);
                void save();
            };
        }
    }
}
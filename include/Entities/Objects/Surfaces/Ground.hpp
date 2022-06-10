#pragma once

#include "Entities/Objects/Object.hpp"
#include "Type.hpp"

#define GROUND_WIDTH 192
#define GROUND_HEIGHT 111

#define GROUND_DIR "./Texture/Scenario/Cemetery/Ground.png"

namespace Entities{
    namespace Objects{
        namespace Surfaces{
            class Ground : public Object{
            private:
                void initializeSprite();
            public:
                Ground(sf::Vector2f position);
                ~Ground();

                void save();
            };
        }
    }
}
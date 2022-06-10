#pragma once

#include "Entities/Objects/Object.hpp"
#include "Type.hpp"

#define STATUE_WIDTH 100
#define STATUE_HEIGHT 100

#define STATUE_DIR "./Textures/Scenario/Cemetery/statue.png"

namespace Entities{
    namespace Objects{
        namespace Obstacles{
            class Statue : public Object{
                private:
                    void initializeSprite();
                
                public:
                    Statue(sf::Vector2f position);
                    ~Statue();

                    void save();
            };
        }
    }
}
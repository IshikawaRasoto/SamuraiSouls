#pragma once

#include "Entities/Objects/Object.hpp"
#include "Type.hpp"

#define STATUE_WIDTH 63
#define STATUE_HEIGHT 75

#define STATUE_DIR "./Textures/Scenario/Cemetery/statue.png"

namespace Entities{
    namespace Objects{
        namespace Props{
            class Statue : public Object{
                private:
                    void initializeSprite();
                
                public:
                    Statue(sf::Vector2f position);
                    ~Statue();

                    void update(float dt);
            };
        }
    }
}
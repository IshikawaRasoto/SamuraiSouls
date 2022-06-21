#pragma once

#include "Entities/Objects/Object.hpp"

#define HOUSE_A_WIDTH 168
#define HOUSE_A_HEIGHT 183
#define HOUSE_A_DIR "./Textures/Scenario/Village/HouseA.png"

namespace Entities{
    namespace Objects{
        namespace Props{
            class HouseA : public Object{
                private:
                    void initializeSprite();
                
                public:
                    HouseA(sf::Vector2f position);
                    ~HouseA();

                    void update(float dt);
            };
        }
    }
}
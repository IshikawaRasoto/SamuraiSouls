#pragma once

#include "Entities/Objects/Object.hpp"

#define HOUSE_B_WIDTH 210
#define HOUSE_B_HEIGHT 244
#define HOUSE_B_DIR "./Textures/Scenario/Village/HouseB.png"

namespace Entities{
    namespace Objects{
        namespace Props{
            class HouseB : public Object{
                private:
                    void initializeSprite();
                
                public:
                    HouseB(sf::Vector2f position);
                    ~HouseB();

                    void update(float dt);
            };
        }
    }
}
#pragma once

#include "Entities/Objects/Object.hpp"

#define HOUSE_C_WIDTH 221
#define HOUSE_C_HEIGHT 183
#define HOUSE_C_DIR "./Textures/Scenario/Village/HouseC.png"

namespace Entities{
    namespace Objects{
        namespace Props{
            class HouseC : public Object{
                private:
                    void initializeSprite();
                
                public:
                    HouseC(sf::Vector2f position);
                    ~HouseC();

                    void save();
                    void update(float dt);
            };
        }
    }
}
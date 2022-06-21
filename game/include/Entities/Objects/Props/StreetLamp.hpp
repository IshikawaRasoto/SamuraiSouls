#pragma once

#include "Entities/Objects/Object.hpp"

#define STREET_LAMP_WIDTH 35
#define STREET_LAMP_HEIGHT 108
#define STREET_LAMP_DIR "./Textures/Scenario/Village/StreetLamp.png"

namespace Entities{
    namespace Objects{
        namespace Props{
            class StreetLamp : public Object{
                private:
                    void initializeSprite();
                
                public:
                    StreetLamp(sf::Vector2f position);
                    ~StreetLamp();

                    void update(float dt);
            };
        }
    }
}
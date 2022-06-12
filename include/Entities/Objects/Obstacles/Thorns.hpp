#pragma once

#include "Entities/Objects/Object.hpp"

#define THORNS_WIDTH 32
#define THORNS_HEIGHT 39
#define THORNS_DIR "./Textures/Scenario/Cemetery/Thorns.png"

namespace Entities{
    namespace Objects{
        namespace Obstacles{
            class Thorns : public Object{
                private:
                    void initializeSprite();
                
                public:
                    Thorns(sf::Vector2f position);
                    ~Thorns();

                    void save();
            };
        }
    }
}
#pragma once

#include "Entities/Objects/Object.hpp"

#define THORNS_WIDTH 32
#define THORNS_HEIGHT 94
#define THORNS_DIR "./Textures/Scenario/Cemetery/Thorns.png"

namespace Entities{
    namespace Objects{
        namespace Obstacles{
            class Thorns : public Object{
                private:
                    static const int dmg;
                    void initializeSprite();
                
                public:
                    Thorns(sf::Vector2f position);
                    ~Thorns();
                    const int getDmg() const;

                    void render();
                    void save();
            };
        }
    }
}
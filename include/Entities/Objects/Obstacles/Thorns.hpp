#pragma once

#include "Entities/Objects/Object.hpp"

#define THORNS_WIDTH 200
#define THORNS_HEIGHT 200

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

                    void update(const float dt);
                    void render();
                    void save();
            };
        }
    }
}
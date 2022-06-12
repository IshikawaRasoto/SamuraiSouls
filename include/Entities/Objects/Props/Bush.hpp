#pragma once

#include "Entities/Objects/Object.hpp"

#define BUSH_WIDTH 76
#define BUSH_HEIGHT 65
#define BUSH_DIR "./Textures/Scenario/Cemetery/Bush.png"

namespace Entities{
    namespace Objects{
        namespace Props{
            class Bush : public Object{
                private:
                    void initializeSprite();
                
                public:
                    Bush(sf::Vector2f position);
                    ~Bush();

                    void save();
                    void update(float dt);
            };
        }
    }
}
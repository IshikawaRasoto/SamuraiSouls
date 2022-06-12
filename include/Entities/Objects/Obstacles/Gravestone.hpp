#pragma once

#include "Entities/Objects/Object.hpp"
#include "Type.hpp"

#define GRAVESTONE_WIDTH 27
#define GRAVESTONE_HEIGHT 33
#define GRAVESTONE_DIR "./Textures/Scenario/Cemetery/Gravestone.png"

namespace Entities{
    namespace Objects{
        namespace Obstacles{
            class Gravestone : public Object{
                private:
                    void initializeSprite();
                
                public:
                    Gravestone(sf::Vector2f position);
                    ~Gravestone();

                    void save();
            };
        }
    }
}
#pragma once

#include "Entities/Objects/Object.hpp"
#include "Type.hpp"

#define BOX_WIDTH 39
#define BOX_HEIGHT 35 

#define BOX_DIR "./Textures/Scenario/Village/Box.png"

namespace Entities{
    namespace Objects{
        namespace Obstacles{
            class Box : public Object{
                public:
                    Box(sf::Vector2f position);
                    ~Box();
                    void update(const float dt);
                    void render();
                    void save();

                private:
                    void initializeSprite();
            };
        }
    }
}
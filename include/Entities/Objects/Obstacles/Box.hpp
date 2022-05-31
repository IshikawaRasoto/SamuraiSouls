#pragma once

#include "Entities/Objects/Object.hpp"

#define BOX_WIDTH 200
#define BOX_HEIGHT 200

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
#pragma once

#include "Entities/Objects/Object.hpp"
#include "Type.hpp"

#define BLOCK_WIDTH 100
#define BLOCK_HEIGHT 100

namespace Entities{
    namespace Objects{
        namespace Surfaces{
            class InvisibleBlock : public Object{
                private:
                    void initializeSprite();

                public:
                    InvisibleBlock(sf::Vector2f position);
                    ~InvisibleBlock();

                    void update(const float dt);
            };
        }
    }
}
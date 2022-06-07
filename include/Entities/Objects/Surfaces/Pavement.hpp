
#pragma once

#include "Entities/Objects/Object.hpp"
#include "Type.hpp"

#define PAVEMENT_WIDTH 2000
#define PAVEMENT_HEIGHT 100

namespace Entities{
    namespace Objects{
        namespace Surfaces{
            class Pavement : public Object{
            private:
                void initializeSprite();
            public:
                Pavement(sf::Vector2f position);
                ~Pavement();

                void update(float dt);
                void save();
            };
        }
    }
}

#pragma once

#include "Entities/Objects/Object.hpp"
#include "Type.hpp"

#define PAVEMENT_WIDTH 192
#define PAVEMENT_HEIGHT 111

#define PAVEMENT_DIR "./Textures/Scenario/Village/Pavement.png"

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
                void collide(Entities::Entity* other, sf::Vector2f intersect);

                void save();
                void update(const float dt);
            };
        }
    }
}
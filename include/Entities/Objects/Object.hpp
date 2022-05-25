#pragma once

#include "Entities/Entity.hpp"

namespace Entities{
    namespace Objects{
        class Object : public Entity{
            public:
                Object(Type t, sf::Vector2f position, sf::Vector2f hitbox);
                virtual ~Object();

                virtual void update(const float dt) = 0;
                virtual void initializeSprite() = 0;
        };
    }
}
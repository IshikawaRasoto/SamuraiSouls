#pragma once

#include "Entities/Entity.hpp"

namespace Entities{
    namespace Objects{
        class Object : public Entity{
            public:
                Object(Type t, sf::Vector2f position, sf::Vector2f size);
                virtual ~Object();

                virtual void save() = 0;

            protected:
                virtual void initializeSprite() = 0;
        };
    }
}
#pragma once

#include "Entities/Entity.hpp"

namespace Entities{
    namespace Characters{
        class Character : public Entities::Entity{
            protected:
                int hp;

            public:
                Character(Type t, sf::Vector2f position, sf::Vector2f hitbox, int hp);
                ~Character();
                const int getHP() const;
                void getDamage(int dmg);
                
            protected:
                virtual void initializeSprite() = 0;
                virtual void update(float dt) = 0;
        };
    }
}

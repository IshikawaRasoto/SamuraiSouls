#pragma once

#include "Entities/Entity.hpp"

namespace Entities{
    namespace Characters{

       enum class Direction{
            Idle = -1,
            Up,
            Down,
            Left,
            Right
        };

        class Character : public Entities::Entity{
            protected:
                int hp;
               // Direction direction;
                Direction dirX;
                Direction dirY;

            public:
                Character(Type t, sf::Vector2f position, sf::Vector2f size, int hp);
                virtual ~Character();
                const int getHP() const;
                void getDamage(int dmg);
                virtual void update(float dt) = 0;
                // virtual void render();

            protected:
                virtual void initializeSprite() = 0;      
        };
    }
}

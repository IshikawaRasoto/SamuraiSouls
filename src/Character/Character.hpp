#pragma once

#include "../Entities/Entity.hpp"
#include "../Type.hpp"

namespace Characters{
    class Character : public Entity{
        protected:
            int hp;

        public:
            Character(Type type, Vector2f position, Vector2f hitbox, int hp);
            ~Character();
            const int getHP() const;
            void getDamage(int dmg);
            
        protected:
            virtual void initializeSprite() = 0;
            virtual void update(float dt) = 0;
    };
}
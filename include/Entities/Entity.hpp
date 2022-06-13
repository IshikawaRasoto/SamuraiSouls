#pragma once

#include "Ent/Ent.hpp"
#include "Snapshots/EntitySnapshot.hpp"

#define GRAVITY 1000.f

namespace Entities{

    class Entity : public Ent{
        protected:
            sf::Vector2f speed; 

        private:
            bool facingLeft;

        public:
            Entity();
            Entity(Type t, sf::Vector2f position, sf::Vector2f size);
            virtual ~Entity();
            
            const sf::Vector2f getSpeed() const;
            const bool getFacingLeft() const;

            void setSpeed(const sf::Vector2f speed);
            void setFacingLeft(const bool facingLeft);

            void move(sf::Vector2f v);

            virtual void collide(Entity* other, sf::Vector2f intersect);
            virtual Snapshots::EntitySnapshot* save();
            virtual void update(const float dt);

        protected:
            virtual void initializeSprite() = 0; 
            void moveOnCollision(Entity* other, sf::Vector2f intersect);  

    };
}
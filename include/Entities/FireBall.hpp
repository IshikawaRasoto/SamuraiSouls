#pragma once
#include "Entities/Entity.hpp"
#include "Entities/Characters/Character.hpp"

#define FIREBALL_WIDTH 100
#define FIREBALL_HEIGHT 100
#define FIREBALL_DMG 20
#define FIREBALL_SPEED_X 75
#define FIREBALL_DIR "./Textures/FireBall.png"
#define AIR_RESISTANCE 900

namespace Entities{
    class FireBall : public Entity{
        public:
            FireBall(sf::Vector2f position);
            ~FireBall();

            void update(float dt);
            void collide(Entity* other, sf::Vector2f intersect = {0.f, 0.f});
            void render();
            void save();
            void shoot(sf::Vector2f position, sf::Vector2f speed);
        
        private:
            void initializeSprite();
    };
}
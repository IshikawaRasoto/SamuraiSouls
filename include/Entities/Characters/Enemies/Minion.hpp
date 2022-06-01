#pragma once

#include "Entities/Characters/Enemies/Enemy.hpp"
#include "Entities/Characters/Player.hpp"

#define MINION_HP 10
#define MINION_DMG 10
#define MINION_WIDTH 100
#define MINION_HEIGHT 100
#define MINION_SPEED_X 80

namespace Entities{
    namespace Characters{
        namespace Enemies{
            class Minion : public Enemy{
                private:
                    static const float attackTime;

                public:
                    Minion(sf::Vector2f pos = sf::Vector2f(0.0, 0.0), Characters::Player *p1 = nullptr, Characters::Player *p2 = nullptr);
                    ~Minion();
                    void update(float dt);
                    void attack();
                    void render();
                    void save();        

                private:
                    void initializeSprite();
            };
        }
    }
}
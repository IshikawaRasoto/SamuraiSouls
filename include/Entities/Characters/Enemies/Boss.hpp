#pragma once

#include "Entities/Characters/Enemies/Enemy.hpp"

#define BOSS_HP 500
#define BOSS_DMG 30
#define BOSS_WIDTH 200
#define BOSSH_HEIGHT 200
#define BOSS_SPEED_X 50

namespace Entities{
    namespace Characters{
        namespace Enemies{
            class Boss : public Enemy{
                private:
                    static const float attackTime;

                public:
                    Boss(sf::Vector2f pos = sf::Vector2f(0.0, 0.0), Player* p1 = nullptr, Player* p2 = nullptr);
                    ~Boss();
                    void initializeSprite();
                    void update(float dt);
                    void attack();
                    void followPlayer();
                    void updateSprite(float dt);
            };
        }
    }
}
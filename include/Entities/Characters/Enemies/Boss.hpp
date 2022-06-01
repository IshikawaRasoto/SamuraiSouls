#pragma once

#include "Entities/Characters/Enemies/Enemy.hpp"
#include "Entities/Characters/Player.hpp"

#include <SFML/System/Vector2.hpp>

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
                    Boss(sf::Vector2f pos = sf::Vector2f(0.0, 0.0), Characters::Player* p1 = nullptr, Characters::Player* p2 = nullptr);
                    ~Boss();
                    void update(float dt);
                    void attack();
                    void followPlayer();
                    void render();
                    void save();

                private:
                    void initializeSprite();
            };
        }
    }
}
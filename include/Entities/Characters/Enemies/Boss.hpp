#pragma once

#include "Entities/Characters/Enemies/Enemy.hpp"
#include "Entities/Characters/Player.hpp"
#include "Entities/FireBall.hpp"

#include <SFML/System/Vector2.hpp>

#define BOSS_HP 500
#define BOSS_DMG 30
#define BOSS_WIDTH 200
#define BOSSH_HEIGHT 200
#define BOSS_SPEED_X 50
#define BOSS_ATK_RANGE 400

#define BOSS_DIR "./Textures/Characters/Boss.png"

namespace Entities{
    namespace Characters{
        namespace Enemies{
            class Boss : public Enemy{
                private:
                    static const float bossAtkTime;
                    FireBall *fireball;

                public:
                    Boss(sf::Vector2f pos = sf::Vector2f(0.0, 0.0), FireBall* fireball = nullptr, Characters::Player* p1 = nullptr, Characters::Player* p2 = nullptr);
                    ~Boss();

                    void movementBoss(); //TODO

                    void update(float dt);
                    void fire();
                    void followPlayer();
                    void render();
                    void save();

                private:
                    void initializeSprite();
            };
        }
    }
}
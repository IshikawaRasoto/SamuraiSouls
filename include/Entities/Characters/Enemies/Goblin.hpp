#pragma once

#include "Entities/Characters/Enemies/Enemy.hpp"

#define GOBLIN_HP 20
#define GOBLIN_DMG 15
#define GOBLIN_WIDTH 200
#define GOBLIN_HEIGHT 200
#define GOBLIN_SPEED_X 50

namespace Entities{
    namespace Characters{
        namespace Enemies{
            class Goblin : public Enemy{
                private:
                    static const float attackTime;
                
                public:
                    Goblin(sf::Vector2f pos = sf::Vector2f(0.0, 0.0), Players::Player* p1 = nullptr, Players::Player* p2 = nullptr);
                    ~Goblin();
                    void update(float dt);
                    void attack();
                    void render();

                private:
                    void initializeSprite();
            };
        }
    }
}
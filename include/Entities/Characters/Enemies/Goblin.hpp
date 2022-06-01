#pragma once

//O segmentation fault era da minha lista kkkkkk

#include "Entities/Characters/Enemies/Enemy.hpp"
#include "Entities/Characters/Player.hpp"

#include <SFML/System/Vector2.hpp>

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
                    Goblin(sf::Vector2f pos = sf::Vector2f(0.0, 0.0), Characters::Player* p1 = nullptr, Characters::Player* p2 = nullptr);
                    ~Goblin();
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
#pragma once

#include "Entities/Characters/Enemies/Enemy.hpp"
#include "Entities/Characters/Player.hpp"

#include <SFML/System/Vector2.hpp>

#define GOBLIN_DIR "./Textures/Characters/Goblin.png"

#define GOBLIN_HP 25
#define GOBLIN_DMG 15
#define GOBLIN_WIDTH 33
#define GOBLIN_HEIGHT 36
#define GOBLIN_SPEED_X 200
#define GOBLIN_ATK_RANGE 30
#define GOBLIN_DX_MAX 400
#define GOBLIN_DX_MIN 30

namespace Entities{
    namespace Characters{
        namespace Enemies{
            class Goblin : public Enemy{
                private:
                    static const float goblinAtkTime;
                
                public:
                    Goblin(sf::Vector2f pos = sf::Vector2f(0.0, 0.0), Characters::Player* p1 = nullptr, Characters::Player* p2 = nullptr);
                    ~Goblin();
                    void update(float dt);
                    void render();
                    void save();
                    void movementGoblin();

                private:
                    void initializeSprite();
            };
        }
    }
}
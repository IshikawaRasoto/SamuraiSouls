#pragma once

#include "Entities/Characters/Enemies/Enemy.hpp"
#include "Entities/Characters/Player.hpp"

#include <SFML/System/Vector2.hpp>

#define SKELETON_HP 50
#define SKELETON_DMG 15
#define SKELETON_WIDTH 200 
#define SKELETON_HEIGHT 200
#define SKELETON_SPEED_X 50

namespace Entities{
    namespace Characters{
        namespace Enemies{
            class Skeleton : public Enemy{
                private:
                    static const float attackTime;

                public:

                    Skeleton(sf::Vector2f pos = sf::Vector2f(0.0, 0.0), Characters::Player* p1 = nullptr, Characters::Player* p2 = nullptr);
                    ~Skeleton();
                    
                    //void movement();

                    void update(float dt);
                    void render();
                    void save();

                private:
                    void initializeSprite();     
            };
        }
    }
}
#pragma once

#include "Entities/Characters/Enemies/Enemy.hpp"
#include "Entities/Characters/Player.hpp"

#include <SFML/System/Vector2.hpp>

#define SKELETON_HP 50
#define SKELETON_DMG 15
#define SKELETON_WIDTH 35 
#define SKELETON_HEIGHT 51
#define SKELETON_SPEED_X 75
#define SKELETON_ATK_RANGE 30
#define SKELETON_DX_MAX 200
#define SKELETON_DX_MIN 30

#define SKELETON_DIR "./Textures/Characters/Skeleton.cpp"

namespace Entities{
    namespace Characters{
        namespace Enemies{
            class Skeleton : public Enemy{
                private:
                    static const float skeletonAtkTime;

                public:

                    Skeleton(sf::Vector2f pos = sf::Vector2f(0.0, 0.0), Characters::Player* p1 = nullptr, Characters::Player* p2 = nullptr);
                    ~Skeleton();
                    
                    void movementSkeleton();

                    void update(float dt);
                    void render();
                    void save();

                private:
                    void initializeSprite();     
            };
        }
    }
}
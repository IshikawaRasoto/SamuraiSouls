#pragma once

#define PLAYER_HP 100
#define PLAYER_DMG 25
#define PLAYER_WIDTH 200
#define PLAYER_HEIGHT 200
#define PLAYER_SPEED_X 80
#define PLAYER_SPEED_Y 80

#include "Entities/Characters/Character.hpp"
#include "Managers/Input.hpp"
using namespace Managers;

namespace Entities{
    namespace Characters{
        namespace Players{
            class Player : public Character{
                private:
                    int points;
                    bool isWalking;

                public:
                    Player(sf::Vector2f position, const bool isPlayerOne = true, InputManager* pIM = nullptr);
                    ~Player();

                    const bool isPlayerOne() const;
                    void updatePts(int points);
                    const bool getPts() const;

                    
                    void update(float dt);
                    void walk(Direction dirX, Direction dirY);
                    void render();
                    void collide(Entity* other, sf::Vector2f intersect);

                private:
                    void initializeSprite();
            };
        }
    }
}
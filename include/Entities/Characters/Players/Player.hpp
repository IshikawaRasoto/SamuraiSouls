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
                    const bool playerOne;
                    static int points;
                    static int lifes;
                    bool isWalking;

                public:
                    Player(sf::Vector2f position, const bool isPlayerOne = true, InputManager* pIM = nullptr);
                    ~Player();

                    const bool isPlayerOne() const;
                    static const int getPts();
                    static void addPts(const int pts);
                    
                    void update(float dt);
                    void walk(Direction direction);
                    void jump();
                    void render();
                    void collide(Entity* other, sf::Vector2f intersect);
                    void save();
                    
                private:
                    void initializeSprite();
            };
        }
    }
}
#pragma once

#define HUNTRESS_HP 100
#define HUNTRESS_WIDTH 400
#define HUNTRESS_HEIGHT 400
#define HUNTRESS_SPEED_X 10
#define HUNTRESS_SPEED_Y 10

#include "Entities/Characters/Character.hpp"
#include "Managers/Input.hpp"
using namespace Managers;

namespace Entities{
    namespace Characters{
        namespace Players{
            class Huntress : public Character{
                private:
                    int points;
                    bool isWalking;

                public:
                    Huntress(sf::Vector2f position, const bool isPlayerOne = true, InputManager* pIM = nullptr);
                    ~Huntress();

                    const bool isPlayerOne() const;
                    void updatePts(int points);
                    const bool getPts() const;

                    
                    void update(float dt);
                    void walk(Direction dirX, Direction dirY);
                    void render();

                private:
                    void initializeSprite();
            };
        }
    }
}
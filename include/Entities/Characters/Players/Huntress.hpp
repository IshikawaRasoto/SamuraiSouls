#pragma once

#define HUNTRESS_HP 100
#define HUNTRESS_WIDTH 400
#define HUNTRESS_HEIGHT 400

#include "Entities/Characters/Character.hpp"
#include "Managers/Input.hpp"
using namespace Managers;

namespace Entities{
    namespace Characters{
        namespace Players{
            class Huntress : public Character{
                private:
                    int points;

                public:
                    Huntress(sf::Vector2f position, const bool isPlayerOne = 1, InputManager* pIM = nullptr);
                    ~Huntress();

                    const bool isPlayerOne() const;
                    void updatePts(int points);
                    const bool getPts() const;

                    void initializeSprite();
                    void update(float dt);
                    
            };
        }
    }
}
#pragma once

#include "../Character.hpp"
#include "Type.hpp"

class Player;

namespace Entities{
    namespace Characters{
        namespace Enemies{
            class Enemy : public Character{
                protected:
                    float atkCD;
                    float timeFromAtk;
                    Player *pP1;
                    Player *pP2;

                public:
                    Enemy(Type t, sf::Vector2f position, sf::Vector2f size, int hp);
                    virtual ~Enemy();
                    virtual void update(float dt) = 0;
                    virtual void attack() = 0;
                    const Player* getNearestPlayer() const;
                    
                protected:
                    virtual void initializeSprite() = 0;

            };
        }
    }
}
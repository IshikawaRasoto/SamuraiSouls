#pragma once

#include "Entities/Characters/Character.hpp"
#include "Entities/Characters/Players/Huntress.hpp"
#include "Type.hpp"



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
                    Enemy(Type t, sf::Vector2f position, sf::Vector2f size, int hp, int dmg, Player* p1 = nullptr, Player* p2 = nullptr);
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
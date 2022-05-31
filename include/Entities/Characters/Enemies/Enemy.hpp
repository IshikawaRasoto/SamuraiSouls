#pragma once

#include "Entities/Characters/Character.hpp"
#include "Entities/Characters/Players/Player.hpp"
#include "Type.hpp"



namespace Entities{
    namespace Characters{
        namespace Enemies{
            class Enemy : public Character{
                protected:
                    float atkCD;
                    float timeFromAtk;
                    Players::Player *pP1;
                    Players::Player *pP2;

                public:
                    Enemy(Type t, sf::Vector2f position, sf::Vector2f size, int hp, int dmg, Players::Player* p1 = nullptr, Players::Player* p2 = nullptr);
                    virtual ~Enemy();
                    virtual void update(float dt) = 0;
                    virtual void attack() = 0;
                    const Players::Player* getNearestPlayer() const;
                    virtual void render() = 0;
                    virtual void save() = 0;
                    
                protected:
                    virtual void initializeSprite() = 0;

            };
        }
    }
}
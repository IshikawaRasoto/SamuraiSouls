#pragma once

#include "Entities/Characters/Character.hpp"
#include "Entities/Characters/Player.hpp"

#include <SFML/System/Vector2.hpp>

#include "Type.hpp"

namespace Entities{
    namespace Characters{
        namespace Enemies{
            class Enemy : public Character{
                protected:
                    float atkCD;
                    float timeFromAtk;
                    Entities::Characters::Player *pP1;
                    Entities::Characters::Player *pP2;

                public:
                    Enemy(Type t, sf::Vector2f position, sf::Vector2f size, int hp, int dmg, Entities::Characters::Player* p1 = nullptr, Entities::Characters::Player* p2 = nullptr);
                    virtual ~Enemy();
                    const Entities::Characters::Player* getNearestPlayer() const;
                    virtual void update(float dt) = 0;
                    virtual void attack() = 0;
                    virtual void render() = 0;
                    virtual void save() = 0;
                    
                protected:
                    virtual void initializeSprite() = 0;

            };
        }
    }
}
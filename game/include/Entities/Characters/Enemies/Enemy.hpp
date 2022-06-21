#pragma once

#include "Entities/Characters/Character.hpp"
#include "Entities/Characters/Player.hpp"

#include <SFML/System/Vector2.hpp>

#include "Type.hpp"

#define MAX_DX 5000.00
#define ATK_RANGE_Y 60

enum class EnemySprite{
    Idle = 0,
    Run,
    Attack,
    Die
};

namespace Entities{
    namespace Characters{
        namespace Enemies{
            class Enemy : public Character{
                protected:
                    float atkCD;
                    float timeFromAtk;
                    Entities::Characters::Player *pP1;
                    Entities::Characters::Player *pP2;
                    float dx;

                public:
                    Enemy(Type t, sf::Vector2f position, sf::Vector2f size, int hp, int dmg, Entities::Characters::Player* p1 = nullptr, Entities::Characters::Player* p2 = nullptr);
                    virtual ~Enemy();
                    Entities::Characters::Player* getNearestPlayer();

                    void setPlayer1(Entities::Characters::Player* player);
                    void setPlayer2(Entities::Characters::Player* player);

                    //virtual void movement(const float spX);
                    virtual void tryAttack(const int dmg);
                    //virtual void tryAttack(const int dmg, const float timeOfAtk);

                    virtual void collide(Entity* other, sf::Vector2f intersect);

                    virtual void update(float dt) = 0;
                    virtual void render() = 0;
                    
                protected:
                    virtual void initializeSprite() = 0;

            };
        }
    }
}
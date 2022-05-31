#pragma once

#include "Entities/Characters/Enemies/Enemy.hpp"

namespace Entities{
    namespace Characters{
        namespace Enemies{
            class Minion : public Enemy{
                private:
                    static const float attackTime;

                public:
                    Minion(sf::Vector2f pos = sf::Vector2f(0.0, 0.0), Players::Player* p1 = nullptr, Players::Player* p2 = nullptr);
                    ~Minion();

            };
        }
    }
}
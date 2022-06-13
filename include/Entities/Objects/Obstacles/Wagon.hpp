#pragma once

#include "Entities/Objects/Object.hpp"
#include "Type.hpp"

#define WAGON_WIDTH 93
#define WAGON_HEIGHT 75
#define WAGON_DIR "./Textures/Scenario/Village/wagon.png"

namespace Entities{
    namespace Objects{
        namespace Obstacles{
            class Wagon : public Object{
                private:
                    void initializeSprite();
                
                public:
                    Wagon(sf::Vector2f position);
                    ~Wagon();

                    void update(float dt);
                    void collide(Entities::Entity* other, sf::Vector2f intersect);
            };
        }
    }
}
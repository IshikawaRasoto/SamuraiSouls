#pragma once

#include "Entities/Objects/Object.hpp"

#define THORNSBASE_WIDTH 32
#define THORNSBASE_HEIGHT 55
#define THORNSBASE_DIR "./Textures/Scenario/Cemetery/ThornsBase.png"

namespace Entities{
    namespace Objects{
        namespace Obstacles{
            class ThornsBase : public Object{
                private:
                    void initializeSprite();
                
                public:
                    ThornsBase(sf::Vector2f position);
                    ~ThornsBase();
                    void update(float dt);
            };
        }
    }
}
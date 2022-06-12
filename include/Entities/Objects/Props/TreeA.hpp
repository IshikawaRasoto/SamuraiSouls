#pragma once

#include "Entities/Objects/Object.hpp"

#define TREE_A_WIDTH 166
#define TREE_A_HEIGHT 117
#define TREE_A_DIR "./Textures/Scenario/Cemetery/TreeA.png"

namespace Entities{
    namespace Objects{
        namespace Props{
            class TreeA : public Object{
                private:
                    void initializeSprite();
                
                public:
                    TreeA(sf::Vector2f position);
                    ~TreeA();

                    void save();
                    void update(float dt);
            };
        }
    }
}
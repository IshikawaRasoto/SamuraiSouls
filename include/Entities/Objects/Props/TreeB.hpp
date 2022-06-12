#pragma once

#include "Entities/Objects/Object.hpp"

#define TREE_B_WIDTH 166
#define TREE_B_HEIGHT 117
#define TREE_B_DIR "./Textures/Scenario/Village/TreeB.png"

namespace Entities{
    namespace Objects{
        namespace Props{
            class TreeB : public Object{
                private:
                    void initializeSprite();
                
                public:
                    TreeB(sf::Vector2f position);
                    ~TreeB();

                    void save();
                    void update(float dt);
            };
        }
    }
}
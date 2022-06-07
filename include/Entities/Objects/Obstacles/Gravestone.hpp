#pragma once

#include "Entities/Objects/Object.hpp"
#include "Type.hpp"

namespace Entities{
    namespace Objects{
        namespace Obstacles{
            class Gravestone : public Object{
                private:
                    void initializeSprite();
                
                public:
                    Gravestone();
                    ~Gravestone();

                    void update(float dt);
                    void save();
            };
        }
    }
}
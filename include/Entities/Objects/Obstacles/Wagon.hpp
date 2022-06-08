#pragma once

#include "Entities/Objects/Object.hpp"
#include "Type.hpp"


namespace Entities{
    namespace Objects{
        namespace Obstacles{
            class Wagon : public Object{
                private:
                    void initializeSprite();
                
                public:
                    Wagon();
                    ~Wagon();

                    void save();
            };
        }
    }
}
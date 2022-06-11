#pragma once

#include "Levels/Level.hpp"
#include "Patterns/StateMachine.hpp"
#include "Graphics/Text.hpp"

#include <string>

#define SECOND_LEVEL_BACKGROUND_DIR "./Textures/Scenario/Cemetery/CemeteryBackGround.png"


namespace Levels{

    class SecondLevel : public Levels::Level{
    // private:
    //     Graphics::Text life;
    //     Graphics::Text points;
    public:

        SecondLevel(Patterns::StateMachine* stateMachine, const bool singlePlayer = true);
        ~SecondLevel();
        
        void reset();
        void centerView();

        void update(float dt);

        template<class T>
        void createStairs(int size, float x, sf::Vector2u objectSize, Lists::EntityList *staticEntities);

        template<class T>
        void createWall(int size, float x, sf::Vector2u objectSize, Lists::EntityList *staticEntities);
        
    };


} // namespace Levels

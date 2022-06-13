#pragma once

#include "Levels/Level.hpp"
#include "Patterns/StateMachine.hpp"
#include "Graphics/Text.hpp"

#include <string>

#define SECOND_LEVEL_BACKGROUND_DIR "./Textures/Scenario/Cemetery/CemeteryBackGround.png"


namespace Levels{

    class SecondLevel : public Levels::Level{
    private:
        Graphics::Text life;
        Graphics::Text points;
    public:

        SecondLevel(Patterns::StateMachine* stateMachine, const bool singlePlayer = true);
        ~SecondLevel();
        
        void reset();
        void centerView();

        void buildObjects(Lists::EntityList *movingEntities);
        void buildStaticEntities(Lists::EntityList *staticEntities);
        void buildRandomEntities(Lists::EntityList *staticEntities, Lists::EntityList *movingEntities);
        void buildCharacters(Lists::EntityList *movingEntities);
        void buildFloor(Lists::EntityList *staticEntities, Lists::EntityList *movingEntities);
        void buildStatues(Lists::EntityList *staticEntities);

        void buildLevel();
        void createPlayer2();

        void load();
        
        void update(float dt);
    };


} // namespace Levels

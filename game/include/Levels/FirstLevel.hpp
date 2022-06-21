#pragma once

#include "Levels/Level.hpp"
#include "Patterns/StateMachine.hpp"
#include "Graphics/Text.hpp"

#include <string>

#define FIRST_LEVEL_BACKGROUND_DIR "./Textures/Scenario/Village/VillageBackground.png"

namespace Levels{

class FirstLevel : public Levels::Level{
public:

    FirstLevel(Patterns::StateMachine* stateMachine, const bool singlePlayer);
    ~FirstLevel();
    
    void reset();
    void centerView();
    
    void createPlayer2();

    void buildObjects(Lists::EntityList *movingEntities);
    void buildStaticEntities(Lists::EntityList *staticEntities);
    void buildRandomEntities(Lists::EntityList *staticEntities, Lists::EntityList *movingEntities);
    void buildCharacters(Lists::EntityList *movingEntities);
    void buildHouses(Lists::EntityList *staticEntities);
    void buildStreetLamps(Lists::EntityList *staticEntities);

    void buildLevel();

    void update(float dt);
    void load();
};


} // namespace Levels

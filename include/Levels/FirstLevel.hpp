#pragma once

#include "Levels/Level.hpp"
#include "Patterns/StateMachine.hpp"
#include "Graphics/Text.hpp"

#include <string>

#define FIRST_LEVEL_BACKGROUND_DIR "./Textures/Scenario/Village/VillageBackground.png"

namespace Levels{

class FirstLevel : public Levels::Level{
private:
    Graphics::Text life;
    Graphics::Text points;

public:

    FirstLevel(Patterns::StateMachine* stateMachine, const bool singlePlayer);
    ~FirstLevel();
    
    void reset();
    void centerView();
    
    void buildObjects(Lists::EntityList *staticEntities);
    void buildRandomEntities(Lists::EntityList *staticEntities, Lists::EntityList *movingEntities);
    void buildCharacters(Lists::EntityList *movingEntities);

    void update(float dt);
};


} // namespace Levels

#pragma once

#include "Levels/Level.hpp"
#include "Patterns/StateMachine.hpp"
#include "Graphics/Text.hpp"

#include <string>

#define FIRST_LEVEL_BACKGROUND_DIR "./Textures/Scenario/Village/VillageBackGround.png"


namespace Levels{

class FirstLevel : public Levels::Level{
// private:
//     Graphics::Text life;
//     Graphics::Text points;

public:

    FirstLevel(Patterns::StateMachine* stateMachine, const bool singlePlayer);
    ~FirstLevel();
    
    void reset();
    void centerView();

    template<class T>
    void createStairs(int size, float x, sf::Vector2u objectSize, Lists::EntityList *staticEntities);

    template<class T>
    void createWall(int size, float x, sf::Vector2u objectSize, Lists::EntityList *staticEntities);

    void update(float dt);
};


} // namespace Levels

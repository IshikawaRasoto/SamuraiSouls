#pragma once

#include <SFML/Graphics.hpp>

#include "Managers/Graphics.hpp"
#include "Managers/Input.hpp"
#include "Managers/Event.hpp"
#include "Levels/Level.hpp"

#include "Patterns/StateMachine.hpp"

class Game : public Patterns::StateMachine{

private:
    bool isDone();
    void update();

    void restartClock();

    sf::Clock clock;
    float deltaTime;

    Levels::Level *currentLevel;
    StateId currentLevelId;

    Managers::GraphicsManager *graphicManager;
    Managers::InputManager *inputManager;
    Managers::EventManager *eventManager;

public:

    Game();
    ~Game();

    Levels::Level* getCurrentLevel();
    StateId getCurrentLevelId();

    void setCurrentLevel(StateId levelStateId);

    void execute();
    void changeCurrentState(const StateId state);
};
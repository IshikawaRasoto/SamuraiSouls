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

    Managers::GraphicsManager *graphicManager;
    Managers::InputManager *inputManager;
    Managers::EventManager *eventManager;

public:

    Game();
    ~Game();

    void execute();
    void changeCurrentState(const StateId state);
};
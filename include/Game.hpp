#pragma once

#include <SFML/Graphics.hpp>

#include "Managers/Graphics.hpp"
#include "Managers/Input.hpp"
#include "Managers/Event.hpp"

#include "Level.hpp"

class Game{

public:

    Game();
    ~Game();

    sf::Time getElapsed();
    bool isDone();

    void update();

    void restartClock();
private:
    sf::Clock clock;
    sf::Time elapsed;

    Level level;
    
    Managers::GraphicsManager *graphicManager;
    Managers::InputManager *inputManager;
    Managers::EventManager *eventManager;
};
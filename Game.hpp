#pragma once

#include <SFML/Graphics.hpp>

#include "Window.hpp"
#include "Managers/Graphics.hpp"
#include "Managers/Colission.hpp"
#include "Managers/Event.hpp"
#include "Lists/EntityList.hpp"

class Game{

public:

    Game();
    ~Game();

    sf::Time getElapsed();
    Window* getWindow();

    void update();
    void render();

    void restartClock();
private:
    sf::Clock clock;
    sf::Time elapsed;

    Managers::GraphicsManager *graphicManager;
    Managers::EventManager *eventManager;
    Lists::EntityList *entitiesList;
};
#pragma once

#include <SFML/Graphics.hpp>

#include "Managers/Graphics.hpp"
#include "Managers/Collision.hpp"
#include "Managers/Input.hpp"
#include "Managers/Event.hpp"
#include "Control/PlayerControl.hpp"

#include "Entities/Objects/Obstacles/Box.hpp"
#include "Entities/Characters/Players/Player.hpp"
#include "Lists/EntityList.hpp"

using namespace Entities::Characters;
using namespace Entities::Objects;

class Game{

public:

    Game();
    ~Game();

    sf::Time getElapsed();
    bool isDone();

    void update();
    void handleInput();
    void render();

    void restartClock();
private:
    sf::Clock clock;
    sf::Time elapsed;

    Lists::EntityList movingEntities;
    Lists::EntityList staticEntities;

    Players::Player player;
    Obstacles::Box box;
    
    Managers::GraphicsManager *graphicManager;
    Managers::InputManager *inputManager;
    Managers::EventManager *eventManager;
    Managers::CollisionManager collisionManager;
    Control::PlayerControl playerControl1;
};
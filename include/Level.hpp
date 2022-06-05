#include "Managers/Collision.hpp"
#include "Managers/Input.hpp"
#include "Managers/Graphics.hpp"
#include "Lists/EntityList.hpp"

#include "Entities/Characters/Player.hpp"
#include "Patterns/State.hpp"

#define LEVEL_Y 400

class Level : public Patterns::State{
private:
    Managers::CollisionManager collisionManager;
    Managers::InputManager *inputManager;
    Managers::GraphicsManager *graphicsManager;
    Lists::EntityList entityList;
    Entities::Characters::Player *player;

public:
    Level(
        Patterns::StateMachine *stateMachine,
        Managers::InputManager *inputManager = Managers::InputManager::getInstance(), 
        Managers::GraphicsManager *graphicsManager = Managers::GraphicsManager::getInstance()
    );
    ~Level();

    void update(float dt);
    void render();
    void reset();
};
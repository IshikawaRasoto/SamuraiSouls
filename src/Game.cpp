#include "Game.hpp"
#include <iostream>

Game::Game(): 
    graphicManager(Managers::GraphicsManager::getInstance()),
    collisionManager(&movingEntities, &staticEntities),
    eventManager(Managers::EventManager::getInstance()),
    inputManager(Managers::InputManager::getInstance()),
    player(new Characters::Player({400.0f, 400.0f})),
    box(new Entities::Objects::Obstacles::Box({400.0f, 1000.0f})),
    playerControl1(player)
{
    movingEntities.addEntity(player);
    staticEntities.addEntity(box);

    eventManager->subscribe("pressed", inputManager);
    eventManager->subscribe("released", inputManager);
    eventManager->subscribe("closed", graphicManager);

    inputManager->subscribe("pressed", &playerControl1);
    inputManager->subscribe("released", &playerControl1);
}

Game::~Game(){}

bool Game::isDone(){
    return graphicManager->isDone();
}

sf::Time Game::getElapsed(){
    return elapsed;
}

void Game::update(){

    float frametime = 1.f / 60.f;

    if(elapsed.asSeconds() < frametime) return;

    eventManager->pollEvents();

    staticEntities.updateAll(elapsed.asSeconds());
    movingEntities.updateAll(elapsed.asSeconds());

    collisionManager.checkCollision();

    graphicManager->centerView(player->getPosition());

    elapsed -= sf::seconds(frametime);
}

void Game::render(){
    graphicManager->beginDraw();
    movingEntities.renderAll();
    staticEntities.renderAll();
    graphicManager->endDraw();
}

void Game::handleInput(){
}

void Game::restartClock(){
    elapsed += clock.restart();
}

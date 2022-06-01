#include "Game.hpp"
#include <iostream>

Game::Game(): 
    graphicManager(Managers::GraphicsManager::getInstance()),
    eventManager(Managers::EventManager::getInstance()),
    inputManager(Managers::InputManager::getInstance()),
    level()
{
    eventManager->subscribe("pressed", inputManager);
    eventManager->subscribe("released", inputManager);
    eventManager->subscribe("closed", graphicManager);
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
    level.update(elapsed.asSeconds());
    level.render();

    elapsed -= sf::seconds(frametime);
}

void Game::restartClock(){
    elapsed += clock.restart();
}

#include "Game.hpp"
#include <iostream>

Game::Game(): 
    graphicManager(Managers::GraphicsManager::getInstance()),
    eventManager(Managers::EventManager::getInstance()),
    inputManager(Managers::InputManager::getInstance()),
    StateMachine()
{

    states[Patterns::StateId::Play] = new States::Level(this);

    currentState = Patterns::StateId::Play;

    eventManager->subscribe("pressed", inputManager);
    eventManager->subscribe("released", inputManager);
    eventManager->subscribe("closed", graphicManager);
    eventManager->subscribe("resize", graphicManager);
}   

Game::~Game(){}

bool Game::isDone(){
    return graphicManager->isDone();
}

sf::Time Game::getElapsed(){
    return elapsed;
}

void Game::execute(){
    while(!isDone()){
        update();
        restartClock();
    }
}

void Game::update(){
    float frametime = 1.f / 60.f;

    if(elapsed.asSeconds() < frametime) return;

    eventManager->pollEvents();
    updateCurrentState(elapsed.asSeconds());

    elapsed -= sf::seconds(frametime);
}

void Game::restartClock(){
    elapsed += clock.restart();
}

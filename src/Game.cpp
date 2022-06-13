#include "Game.hpp"

#include "Levels/FirstLevel.hpp"
#include "Levels/SecondLevel.hpp"

#include "Menus/MainMenu.hpp"
#include "Menus/GameOver.hpp"
#include "Menus/Pause.hpp"
#include "Menus/Leaderboard.hpp"

#include <iostream>

Game::Game(): 
    graphicManager(Managers::GraphicsManager::getInstance()),
    eventManager(Managers::EventManager::getInstance()),
    inputManager(Managers::InputManager::getInstance()),
    StateMachine(),
    deltaTime(0.f)
{

    states[Patterns::StateId::FirstLevel] = new Levels::FirstLevel(this, true);
    states[Patterns::StateId::SecondLevel] = new Levels::SecondLevel(this, true);
    states[Patterns::StateId::MainMenu] = new Menus::MainMenu(this);
    states[Patterns::StateId::GameOver] = new Menus::GameOver(this);
    states[Patterns::StateId::Pause] = new Menus::Pause(this);
    states[Patterns::StateId::Leaderboard] = new Menus::Leaderboard(this);

    currentState = Patterns::StateId::MainMenu;

    eventManager->subscribe("pressed", inputManager);
    eventManager->subscribe("released", inputManager);
    eventManager->subscribe("closed", graphicManager);
    eventManager->subscribe("resize", graphicManager);
}   

Game::~Game(){}

bool Game::isDone(){
    return graphicManager->isDone();
}

void Game::execute(){
    while(!isDone()){
        update();
    }
}

void Game::update(){

    deltaTime = clock.restart().asSeconds();

    eventManager->pollEvents();
    updateCurrentState(deltaTime);
}

void Game::changeCurrentState(const StateId state){
    if(states[state]->getNeedReset()){
        states[state]->reset();
        states[state]->setNeedReset(false);
    }

    //Carregamos os dados da leaderboard novamente apenas se houver um gameOver.
    if(state == StateId::GameOver){
        states[StateId::Leaderboard]->setNeedReset(true);
    }

    if(state == StateId::MainMenu){
        Levels::Level::getCurrentLevel()->reset();
    }

    lastState = currentState;
    currentState = state;
}
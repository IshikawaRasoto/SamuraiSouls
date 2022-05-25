#include "Game.hpp"
#include <iostream>

Game::Game(): 
    graphicManager(GraphicsManager::getInstance()),
    collisionManager(&movingEntities, &staticEntities),
    player({0.0f, 0.0f})
{
    movingEntities.addEntity(&player);
}

Game::~Game(){}

sf::Time Game::getElapsed(){
    return elapsed;
}

void Game::update(){

    float frametime = 1.f / 60.f;

    if(elapsed.asSeconds() < frametime) return;

    player.update(elapsed.asSeconds());
    graphicManager->update();
    collisionManager.checkColision();

    elapsed -= sf::seconds(frametime);
}

void Game::render(){
    graphicManager->beginDraw();
    movingEntities.renderAll();
    staticEntities.renderAll();
    graphicManager->endDraw();
}

void Game::handleInput(){
    
    Direction dirX = Direction::Idle, dirY = Direction::Idle;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        dirY = Direction::Up;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        dirY = Direction::Down;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        dirX = Direction::Left;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        dirX = Direction::Right;
    }

    player.walk(dirX, dirY);
}

void Game::restartClock(){
    elapsed += clock.restart();
}

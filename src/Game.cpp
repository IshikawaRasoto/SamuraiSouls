#include "Game.hpp"
#include <iostream>

Game::Game(): 
    graphicManager(GraphicsManager::getInstance()),
    collisionManager(&movingEntities, &staticEntities),
    player({0.0f, 0.0f}),
    box({400.0f,400.0f})
{
    movingEntities.addEntity(&player);
    staticEntities.addEntity(&box);
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

    player.update(elapsed.asSeconds());
    box.update(elapsed.asSeconds());
    
    graphicManager->update();
    collisionManager.checkCollision();

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
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        dirX = Direction::Left;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        dirX = Direction::Right;
    }

    player.walk(dirX, dirY);
}

void Game::restartClock(){
    elapsed += clock.restart();
}
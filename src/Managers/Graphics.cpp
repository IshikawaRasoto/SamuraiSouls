#include "Managers/Graphics.hpp"
#include "config.hpp"

using namespace Managers;

GraphicsManager::GraphicsManager(){
    setup(windowName, sf::Vector2u(windowSize.x,windowSize.y));
}

GraphicsManager::GraphicsManager(const std::string &title, const sf::Vector2u &size){
    setup(title, size);
}

GraphicsManager::~GraphicsManager(){}

void GraphicsManager::beginDraw(){
    window.clear(sf::Color::Black);
}

void GraphicsManager::endDraw(){
    window.display();
}

void GraphicsManager::update(){

    sf::Event event;

    while(window.pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                done = true;
                break;
            case sf::Event::KeyPressed:
                switch(event.key.code){
                    case sf::Keyboard::F5:
                        toggleFullscreen();
                        break;
                }
                break;
        }
    }
}

bool GraphicsManager::isDone(){
    return done;
}

bool GraphicsManager::isFullscreen(){
    return fullscreen;
}

sf::Vector2u GraphicsManager::getSize(){
    return size;
}

void GraphicsManager::toggleFullscreen(){
    fullscreen = !fullscreen;

    destroy();
    create();
}

void GraphicsManager::draw(sf::Drawable &drawable){
    window.draw(drawable);
}

void GraphicsManager::setup(const std::string &title, const sf::Vector2u &size){
    this->title = title;
    this->size = size;
    fullscreen = false;
    done = false;

    create();
}

void GraphicsManager::destroy(){
    window.close();
}

void GraphicsManager::create(){

    auto style = fullscreen ? sf::Style::Fullscreen : sf::Style::Default;

    window.setFramerateLimit(60);
    window.create({size.x, size.y, 32}, title, style);
}

GraphicsManager* GraphicsManager::instance = nullptr;

GraphicsManager* GraphicsManager::getInstance(){
    if(instance == nullptr)
        instance = new GraphicsManager;
    return instance;
}
#include "Window.hpp"

Window::Window(){
    setup("Game++", sf::Vector2u(800,600));
}

Window::Window(const std::string &title, const sf::Vector2u &size){
    setup(title, size);
}

Window::~Window(){}

void Window::beginDraw(){
    window.clear(sf::Color::Black);
}

void Window::endDraw(){
    window.display();
}

void Window::update(){

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

bool Window::isDone(){
    return done;
}

bool Window::isFullscreen(){
    return fullscreen;
}

sf::Vector2u Window::getSize(){
    return size;
}

void Window::toggleFullscreen(){
    fullscreen = !fullscreen;

    destroy();
    create();
}

void Window::draw(sf::Drawable &drawable){
    window.draw(drawable);
}

void Window::setup(const std::string &title, const sf::Vector2u &size){
    this->title = title;
    this->size = size;
    fullscreen = false;
    done = false;

    create();
}

void Window::destroy(){
    window.close();
}

void Window::create(){

    auto style = fullscreen ? sf::Style::Fullscreen : sf::Style::Default;

    window.setFramerateLimit(60);
    window.create({size.x, size.y, 32}, title, style);
}
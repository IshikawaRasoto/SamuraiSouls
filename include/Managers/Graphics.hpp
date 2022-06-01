#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "Patterns/Observer.hpp"

namespace Managers{

class EventManager;

class GraphicsManager : public Patterns::Observer<EventManager>{
private:

    GraphicsManager();

    void setup(const std::string &title, const sf::Vector2u &size);
    void destroy();
    void create();

    sf::RenderWindow window;
    sf::Vector2u size;
    sf::View view;
    std::string title;

    bool done;
    bool fullscreen;

    void update(EventManager *subject);

    // SINGLETON
    static GraphicsManager *instance;

public:

    ~GraphicsManager();

    void beginDraw();
    void endDraw();

    void update();

    bool isDone();
    bool isFullscreen();

    sf::Vector2u getSize();
    sf::Window* getWindow();

    void toggleFullscreen();
    void draw(sf::Drawable &drawable);
    void centerView(sf::Vector2f position);

    static GraphicsManager* getInstance();
};

}


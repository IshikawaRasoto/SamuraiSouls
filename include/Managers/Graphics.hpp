#pragma once

#include <string>
#include <SFML/Graphics.hpp>

namespace Managers{

class GraphicsManager{

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

    static GraphicsManager* getInstance();

private:

    GraphicsManager();

    void setup(const std::string &title, const sf::Vector2u &size);
    void destroy();
    void create();

    sf::RenderWindow window;
    sf::Vector2u size;
    std::string title;

    bool done;
    bool fullscreen;

    // SINGLETON
    static GraphicsManager* instance;
};

}


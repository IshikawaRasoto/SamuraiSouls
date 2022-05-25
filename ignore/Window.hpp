#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class Window{

public:

    Window();
    Window(const std::string &title, const sf::Vector2u &size);
    ~Window();

    void beginDraw();
    void endDraw();

    void update();

    bool isDone();
    bool isFullscreen();

    sf::Vector2u getSize();

    void toggleFullscreen();
    void draw(sf::Drawable &drawable);

private:
    void setup(const std::string &title, const sf::Vector2u &size);
    void destroy();
    void create();

    sf::RenderWindow window;
    sf::Vector2u size;
    std::string title;

    bool done;
    bool fullscreen;
};
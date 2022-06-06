#pragma once

#include <string>
#include <map>

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
    void clearTextures();
    void clearFonts();

    sf::RenderWindow window;
    sf::Vector2u size;
    sf::View view;
    std::string title;

    bool done;
    bool fullscreen;

    void update(EventManager *subject);

    // SINGLETON
    static GraphicsManager *instance;
    std::map<std::string, sf::Texture*> textures;
    std::map<std::string, sf::Font*> fonts;
public:

    ~GraphicsManager();

    sf::Texture* getTexture(std::string path);
    sf::Font* getFont(std::string path);

    void beginDraw();
    void endDraw();

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


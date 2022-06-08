#pragma once

#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

#include "Managers/Graphics.hpp"

#define FONT_PATH ""
#define TEXT_SIZE 24
#define TEXT_COLOR sf::Color::White

namespace Graphics{
    
enum TextAlignment{
    Left,
    Right,
    Center
};

class Text{
private:

    sf::Text text;
    std::string value;

    static Managers::GraphicsManager *graphicsManager;

public:

    Text(
        std::string value = "", 
        sf::Vector2f position = sf::Vector2f(0.0f, 0.0f),
        std::string fontPath = FONT_PATH
    );
    ~Text();

    unsigned int getFontSize();
    sf::Vector2f getSize();
    sf::Vector2f getPosition();
    std::string getValue();

    void setPosition(sf::Vector2f position);
    void setColor(const unsigned int R, const unsigned int G, const unsigned int B);
    void setColor(sf::Color color);
    void setFontSize(const unsigned int size);
    void setTextAlignment(TextAlignment alignment);
    void setValue(std::string value);

    void render();
};

}


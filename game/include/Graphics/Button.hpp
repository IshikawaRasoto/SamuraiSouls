#pragma once

#include "Text.hpp"
#include "Ent/Ent.hpp"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <string>

#define BUTTON_FONT_SIZE 24
#define BUTTON_FONT_COLOR sf::Color::White

#define BUTTON_FONT_SELECTED_COLOR sf::Color::Black

#define BUTTON_TEXTURE_PATH "path"

#define BUTTON_SIZE_X 0
#define BUTTON_SIZE_Y 0

#define BUTTON_FONT_DIR "./fonts/Arial.ttf"

namespace Graphics{

class Button : public Ent{
private:
    Text content;
    sf::Color selectedColor;
    sf::Color defaultColor;
    bool selected;

public:
    Button(std::string content = "", sf::Vector2f position = sf::Vector2f(0.0f, 0.0f), std::string fontDir = BUTTON_FONT_DIR);
    ~Button();

    std::string getContent();
    sf::Color getSelectedColor();
    sf::Color getDefaultColor();

    void setContent(std::string content);
    void setSelectedColor(sf::Color color);
    void setDefaultColor(sf::Color color);

    void initializeSprite();
    void render();
    void update(float dt);

    void select(bool selected);
};

}
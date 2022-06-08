#pragma once

#include "Text.hpp"
#include "Ent/Ent.hpp"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <string>

#define BUTTON_FONT_SIZE 24
#define BUTTON_FONT_COLOR sf::Color::White

#define BUTTON_TEXTURE_PATH "path"

#define BUTTON_SIZE_X 0
#define BUTTON_SIZE_Y 0

#define BUTTON_FONT_DIR "./fonts/Arial.ttf"

namespace Graphics{

class Button : public Ent{
private:
    Text content;
    bool selected;

public:
    Button(std::string content = "", sf::Vector2f position = sf::Vector2f(0.0f, 0.0f), std::string fontDir = BUTTON_FONT_DIR);
    ~Button();

    std::string getContent();
    void setContent(std::string content);

    void initializeSprite();
    void render();
    void update(float dt);

    void select(bool selected);
};

}
#pragma once

#include "Text.hpp"
#include "Ent/Ent.hpp"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <string>

#define BUTTON_FONT_SIZE 18
#define BUTTON_FONT_COLOR sf::Color::Black

#define BUTTON_TEXTURE_PATH "path"

#define BUTTON_SIZE_X 100
#define BUTTON_SIZE_Y 50

namespace Graphics{

class Button : public Ent{
private:
    Text content;
    bool selected;

public:
    Button(std::string content = "", sf::Vector2f position = sf::Vector2f(0.0f, 0.0f));
    ~Button();

    std::string getContent();
    void setContent(std::string content);

    void initializeSprite();
    void render();
    void update(float dt);

    void select(bool selected);
};

}
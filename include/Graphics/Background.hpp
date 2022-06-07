#include "Ent/Ent.hpp"
#include <SFML/System/Vector2.hpp>
#include <string>

namespace Graphics{

class Background : public Ent{
    Background(
        sf::Vector2f position = sf::Vector2f(0.0f,0.0f), 
        std::string path = "",
        sf::Vector2f size = sf::Vector2f(0.0f, 0.0f)
    );

    ~Background();

    void initializeSprite();
    void render();
    void update();
};


}
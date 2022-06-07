#pragma once

#include "standard.hpp"
#include "Managers/Graphics.hpp"
#include <string>
using namespace Managers;

class Animator{
    private:
        GraphicsManager* pGM;
        sf::RectangleShape body;
    public:
        Animator(sf::Vector2f size = sf::Vector2f(0.0,0.0));
        ~Animator();
        void render();
        void update(sf::Vector2f position);
        void setGraphMngr(GraphicsManager* pGraphMngr);
        void initializeTexture(std::string path, sf::Vector2u imageCount);
        sf::RectangleShape* getRectangleShape();
};
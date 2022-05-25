#pragma once

#include "standard.hpp"
#include "Managers/Graphics.hpp"
using namespace Managers;

class Animation{
    private:
        GraphicsManager* pGM;
        sf::RectangleShape body;
    public:
        Animation();
        ~Animation();
        void render();
        void update(sf::Vector2f position);
        void setGraphMngr(GraphicsManager* pGraphMngr);
};
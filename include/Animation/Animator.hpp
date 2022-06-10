#pragma once

#include "standard.hpp"
#include "Managers/Graphics.hpp"
#include <string>
using namespace Managers;

class Animator{
    private:
        static GraphicsManager* pGM;
        sf::RectangleShape body;
        sf::Vector2u imgCount;
        sf::Vector2u currentImg;
        sf::Texture* texture;
        sf::IntRect uvRect;
        float deltaTime;
        //static const float switchTime;

    public:
        Animator(sf::Vector2f size = sf::Vector2f(0.0,0.0));
        ~Animator();
        void render();
        void update(sf::Vector2f position);
        void update(sf::Vector2f position, int row, int qnt_img, float dt, bool facingLeft, float switchTime);
        void setGraphMngr(GraphicsManager* pGraphMngr);
        void initializeTexture(std::string path, sf::Vector2u imageCount);
        sf::RectangleShape* getRectangleShape();
};
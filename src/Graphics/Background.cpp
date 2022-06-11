#include "Graphics/Background.hpp"
#include "config.hpp"
#include "Type.hpp"

using namespace Graphics;

Background::Background(std::string path):
Ent(Type::Background, {0.0f, 0.0f}, {WINDOW_SIZE_X, WINDOW_SIZE_Y})
{
    this->path = path;
    initializeSprite();    
}

Background::Background():
Ent(Type::Background, {0.0f, 0.0f}, {WINDOW_SIZE_X, WINDOW_SIZE_Y})
{
    path = "";
}

Background::~Background(){}

void Background::initializeSprite(){
    animator->initializeTexture(path, {1,1});
}
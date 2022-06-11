#include "Managers/Graphics.hpp"
#include "config.hpp"
#include <iostream>

using namespace Managers;

GraphicsManager::GraphicsManager(){
    setup(WINDOW_NAME, sf::Vector2u(WINDOW_SIZE_X,WINDOW_SIZE_Y));
}

GraphicsManager::~GraphicsManager(){
    clearTextures();
    clearFonts();
}

//Funcao para retornar a textura do path fornecido.
sf::Texture* GraphicsManager::getTexture(std::string path){
    std::map<std::string, sf::Texture*>::iterator it = textures.find(path);

    //Se a textura não existe no map de textures, criamos uma nova textura a partir do path.
    if(it == textures.end()){
        sf::Texture *newTexture = new sf::Texture();

        //Caso não seja possível carregar a textura, retornamos apenas um ponteiro vazio.
        if(!newTexture->loadFromFile(path)){
            std::cout << "[GraphicsManager] Falha ao carregar uma textura a partir de \"" << path << "\".\n";
            return nullptr;
        };

        textures[path] = newTexture;
    }

    return textures[path];
}

//Funcao para retornar a fonte do path fornecido.
sf::Font* GraphicsManager::getFont(std::string path){
    std::map<std::string, sf::Font*>::iterator it = fonts.find(path);

    //Se a fonte não existe no map de fonte, criamos uma nova Font a partir do path.
    if(it == fonts.end()){
        sf::Font *newFont = new sf::Font();

        //Caso não seja possível carregar a font a partir do path, retornamos apenas um ponteiro vazio
        if(!newFont->loadFromFile(path)){
            std::cout << "[GraphicsManager] Falha ao carregar uma fonte a partir de \"" << path << "\".\n";
            return nullptr;
        };

        fonts[path] = newFont;
    }

    return fonts[path];
}

void GraphicsManager::beginDraw(){
    window.clear(sf::Color::Black);
}

void GraphicsManager::endDraw(){
    window.display();
}

bool GraphicsManager::isDone(){
    return done;
}

void GraphicsManager::setDone(bool done){
    this->done = done;
}

bool GraphicsManager::isFullscreen(){
    return fullscreen;
}

sf::Vector2u GraphicsManager::getSize(){
    return size;
}

sf::Window* GraphicsManager::getWindow(){
    return &window;
}

void GraphicsManager::toggleFullscreen(){
    fullscreen = !fullscreen;

    destroy();
    create();
}

void GraphicsManager::draw(sf::Drawable &drawable){
    window.draw(drawable);
}

void GraphicsManager::centerView(sf::Vector2f position){
    view.setCenter(position);
    window.setView(view);
}

void GraphicsManager::handleWindowResize(){
    float aspectRatio = float(window.getSize().x) / window.getSize().y;
    view.setSize(sf::Vector2f(WINDOW_SIZE_Y * aspectRatio, WINDOW_SIZE_Y));
    window.setView(view);
}

void GraphicsManager::setup(const std::string &title, const sf::Vector2u &size){
    this->title = title;
    this->size = size;
    fullscreen = false;
    done = false;

    create();
}

void GraphicsManager::destroy(){
    window.close();
}

void GraphicsManager::create(){

    auto style = fullscreen ? sf::Style::Fullscreen : sf::Style::Default;

    //window.setFramerateLimit(60);
    window.create({size.x, size.y, 32}, title, style);
}

GraphicsManager* GraphicsManager::instance = nullptr;

GraphicsManager* GraphicsManager::getInstance(){
    if(instance == nullptr)
        instance = new GraphicsManager();
    return instance;
}

void GraphicsManager::clearTextures(){
    for(auto &it : textures){
        if(it.second)
            delete it.second;
    }
}

void GraphicsManager::clearFonts(){
    for(auto &it : fonts){
        if(it.second)
            delete it.second;
    }
}
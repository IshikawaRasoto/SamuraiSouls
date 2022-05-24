#pragma once

#include "../Type.hpp"
#include <SFML/Window.hpp>

class Animation;

class Ent{
    protected:
        Animation* animation;
        Type type;
        sf::Vector2f position;
    
    public:
        Ent();
        Ent(Type type, sf::Vector2f position);
        virtual ~Ent();

        const sf::Vector2f getPosition() const;
        const Type getType() const;
        void changePosition(sf::Vector2f position);
        
        virtual void initializeSprite() = 0;
        virtual void update(float dt) = 0;
        virtual void render();
};
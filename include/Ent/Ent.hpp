#pragma once

#include "Animation/Animation.hpp"


class Animation;

class Ent{
    protected:
        Animation* animation;
        Type t;
        sf::Vector2f position;
        sf::Vector2f size;

        virtual void initializeSprite() = 0;
    
    public:
        Ent();
        Ent(Type t, sf::Vector2f position, sf::Vector2f size);
        virtual ~Ent();

        const sf::Vector2f getPosition() const;
        const Type getType() const;
        const sf::Vector2f getSize() const;
        
        void setPosition(sf::Vector2f position);
        
        virtual void update(const float dt) = 0;
        virtual void render();
};
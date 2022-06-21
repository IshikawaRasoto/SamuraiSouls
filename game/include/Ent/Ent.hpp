#pragma once

#include "Animation/Animator.hpp"
#include "standard.hpp"

class Ent{
    protected:
        Animator animator;
        Type t;  // Type eh equivale a int id do UML fornecido.
        sf::Vector2f position;
        sf::Vector2f size;
        bool showing;
    
    public:
        Ent();
        Ent(Type t, sf::Vector2f position, sf::Vector2f size);
        virtual ~Ent();

        const sf::Vector2f getPosition() const;
        const Type getType() const;
        const sf::Vector2f getSize() const;
        const bool getIsShowing() const;
        
        void setPosition(sf::Vector2f position);
        void setIsShowing(const bool showing);
        void moveBody(const sf::Vector2f v);
        
        virtual void update(const float dt);
        virtual void render();

    protected:
        virtual void initializeSprite() = 0;
};
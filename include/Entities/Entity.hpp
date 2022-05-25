#pragma once

#include "Ent/Ent.hpp"

namespace Entities{

class Entity : public Ent{
protected:

    sf::Vector2f speed;
    sf::Vector2f hitbox;

private:

    bool showing;
 //   bool facingLeft;

public:
    Entity();
    Entity(Type t, sf::Vector2f position, sf::Vector2f hitbox);
    ~Entity();
    
    const sf::Vector2f getSpeed() const;
    const sf::Vector2f getHitbox() const;
    const bool getIsShowing() const;
//    const bool getIsFacingLeft() const;

    void setSpeed(const sf::Vector2f speed);
    void setHitbox(const sf::Vector2f hitbox);
    void setIsShowing(const bool showing);
//    void setIsFacingLeft(const bool facingLeft);

//    virtual void render();
    virtual void update(const float dt) = 0;
    virtual void initializeSprite() = 0;
};
}


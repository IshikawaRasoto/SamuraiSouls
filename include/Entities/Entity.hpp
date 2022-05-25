#pragma once

#include "Ent/Ent.hpp"

namespace Entities{

class Entity : public Ent{
protected:
    sf::Vector2f speed;
    virtual void initializeSprite() = 0;

private:

    bool showing;

public:
    Entity();
    Entity(Type t, sf::Vector2f position, sf::Vector2f size);
    virtual ~Entity();
    
    const sf::Vector2f getSpeed() const;
    const bool getIsShowing() const;

    void setSpeed(const sf::Vector2f speed);
    void setIsShowing(const bool showing);

    virtual void update(const float dt) = 0;
    virtual void collide(Entity* other, sf::Vector2f intersect);
    // virtual void render();
    
};
}


#include <vector>
#include <SFML/System/Vector2.hpp>

#include "Entities/Entity.hpp"
#include "Entities/Objects/Surfaces/Pavement.hpp"

namespace Levels{

template <class T>
class StructuresFactory{
public:
    static std::vector<Entities::Entity*> createFloor(float n, sf::Vector2f position, sf::Vector2u objectSize);
    static std::vector<Entities::Entity*> createStairs(int size, sf::Vector2f position, sf::Vector2u objectSize);
    static std::vector<Entities::Entity*> createWall(int size, sf::Vector2f position, sf::Vector2u objectSize);
};

template <class T>
std::vector<Entities::Entity*> StructuresFactory<T>::createFloor(float n, sf::Vector2f position, sf::Vector2u objectSize){

    std::vector<Entities::Entity*> objects;
    
    for(float i = 0; i < n; i++){
        T *object = new T({position.x + i*objectSize.x, position.y});
        objects.push_back(object);
    }

    return objects;
}

template <class T>
std::vector<Entities::Entity*> StructuresFactory<T>::createStairs(int size, sf::Vector2f position, sf::Vector2u objectSize){
    std::vector<Entities::Entity*> objects;

    for(float i = 0; i < size; i++){
        for(float j = i; j < size; j++){
            T *object = new T({position.x+j*objectSize.x, position.y - (objectSize.y*i + objectSize.y/2)});
            objects.push_back(object);
        }
    }

    return objects;
}

template <class T>
std::vector<Entities::Entity*> StructuresFactory<T>::createWall(int size, sf::Vector2f position, sf::Vector2u objectSize){
    std::vector<Entities::Entity*> objects;

    for(float i = 0; i < size; i++){
        T *object = new T({position.x, position.y - (objectSize.y*i + objectSize.y/2)});
        objects.push_back(object);
    }

    return objects;
}

}



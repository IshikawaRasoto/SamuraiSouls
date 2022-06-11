#include <vector>
#include <SFML/System/Vector2.hpp>

#include "Entities/Entity.hpp"
#include "Entities/Objects/Surfaces/Pavement.hpp"

namespace Levels{

template <class T>
class StructuresFactory{
public:
    static std::vector<Entities::Entity*> createFloor(float min, float max, sf::Vector2u objectSize);
    static std::vector<Entities::Entity*> createStairs(int size, float x, sf::Vector2u objectSize);
    static std::vector<Entities::Entity*> createWall(int size, float x, sf::Vector2u objectSize);
};

template <class T>
std::vector<Entities::Entity*> StructuresFactory<T>::createFloor(float min, float max, sf::Vector2u objectSize){

    std::vector<Entities::Entity*> objects;
    
    for(float i = min; i < max; i++){
        T *object = new T({i*objectSize.x, 0});
        objects.push_back(object);
    }

    return objects;
}

template <class T>
std::vector<Entities::Entity*> StructuresFactory<T>::createStairs(int size, float x, sf::Vector2u objectSize){
    std::vector<Entities::Entity*> objects;

    for(float i = 0; i < size; i++){
        for(float j = i; j < size; j++){
            T *object = new T({x+j*objectSize.x, -PAVEMENT_HEIGHT/2 - (objectSize.y*i + objectSize.y/2)});
            objects.push_back(object);
        }
    }

    return objects;
}

template <class T>
std::vector<Entities::Entity*> StructuresFactory<T>::createWall(int size, float x, sf::Vector2u objectSize){
    std::vector<Entities::Entity*> objects;

    for(float i = 0; i < size; i++){
        T *object = new T({x, -PAVEMENT_HEIGHT/2 - (objectSize.y*i + objectSize.y/2)});
        objects.push_back(object);
    }

    return objects;
}

}



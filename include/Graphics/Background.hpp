#include "Ent/Ent.hpp"
#include <SFML/System/Vector2.hpp>
#include <string>

namespace Graphics{

class Background : public Ent{
private:
    std::string path;
    void initializeSprite();
public:
    Background(std::string path);
    ~Background();
};


}
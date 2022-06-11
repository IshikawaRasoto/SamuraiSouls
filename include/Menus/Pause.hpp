#include "Patterns/State.hpp"
#include "Patterns/StateMachine.hpp"
#include "Menu.hpp"
#include "Graphics/Text.hpp"

#define PAUSE_FONT_DIR "./fonts/SpecialElite.ttf"
#define PAUSE_BACKGROUND_DIR "./Textures/Scenario/Village/VillageBackground.png"
#define PAUSE_MARGIN_BUTTON 80

namespace Menus{

class Pause : public State, public Menu{
private:
    Graphics::Text title;
public:

    Pause(StateMachine *stateMachine);
    ~Pause();

    void update(const float dt);
    void render();
    void execute();

    void reset();
};

}
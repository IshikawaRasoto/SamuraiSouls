#pragma once

#define PLAYER_HP 100
#define PLAYER_DMG 50
#define PLAYER_WIDTH 37
#define PLAYER_HEIGHT 44
#define PLAYER_SPEED_X 150
#define PLAYER_SPEED_Y 400
#define PLAYER_ATK_RANGE_X 110
#define PLAYER_ATK_RANGE_Y 69
#define PLAYER_MAX_Y 500

enum class PlayerSprite{
    Idle = 0,
    Run,
    Attack, 
    Jump,
    Fall,
    Die
};

#include "Entities/Characters/Character.hpp"
#include "Managers/Control/PlayerControl.hpp"
#include "Snapshots/PlayerSnapshot.hpp"

#define MASTER_DIR "./Textures/Characters/Master.png"
#define APPRENTICE_DIR "./Textures/Characters/Apprentice.png"

using namespace Managers::Control;

namespace Entities{
    namespace Characters{
        class Player : public Character{
            private:
                static const float playerAtkTime; 
                const bool playerOne;
                static int points;
                bool isWalking;
                bool canJump;
                float timeFromAtk;
                float atkCD;
                bool atkCollision;//Controle de uma colisão de ataque por ataque
                Control::PlayerControl* playerControl;

            public:
                Player(
                    sf::Vector2f position,
                    const bool isPlayerOne = true,
                    Control::PlayerControl* playerControl = nullptr
                );
                ~Player();

                const bool getIsPlayerOne() const;
                const bool getIsAtkCollision() const;
                static const int getPts();
                Control::PlayerControl* getPlayerControl() const;

                static void addPts(const int pts);
                static void setPts(const int pts);

                void setHp(int hp);
                void setAtkCollision(const bool atkCollision);
                
                void update(float dt);
                void walk(Direction direction);
                void jump();
                void render();
                void collide(Entity* other, sf::Vector2f intersect);
                Snapshots::PlayerSnapshot* save();
                void playerAtk(Entities::Entity* other, Type t);

                bool statusAtk(const float dt);
                
            private:
                void initializeSprite();
        };
    }
}
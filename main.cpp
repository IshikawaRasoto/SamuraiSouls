#include "Game.hpp"
#include <iostream>

int main(){
    
    Game game;

    while(!game.isDone()){
        game.handleInput();
        game.update();
        game.render();
        game.restartClock();
    }

    return 0;
}
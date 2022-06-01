#include "include/Game.hpp"
#include <iostream>

int main(){
    
    Game game;

    while(!game.isDone()){
        game.update();
        game.restartClock();
    }

    return 0;
}
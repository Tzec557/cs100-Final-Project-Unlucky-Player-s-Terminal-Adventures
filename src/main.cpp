#include <iostream>
#include "../header/Game.hpp"
#include "../header/Point.hpp"
using namespace std;

int main(){
    Game *gameTime=new Game();
    gameTime->StartGame();
    delete gameTime;
    return 0;
}

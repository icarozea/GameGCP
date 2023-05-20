#ifndef MenuState_h
#define MenuState_h

#include "State.h"
#include "Game.h"

class MenuState: public State{
public:
    MenuState(Game *game): State(game, "Menu State"){
    };
    
    ~MenuState(){};
    
    void update();
    void draw();
    void next();

    float initTime = 0;
    int intCoins = 0;
        
};
#endif 

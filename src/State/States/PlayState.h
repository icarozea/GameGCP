#ifndef PlayState_h
#define PlayState_h

#include "State.h"
#include "Game.h"


class PlayState : public State {
public:
	PlayState(Game* game, float initTime, float initCoins);

	~PlayState() {};

	void update();
	void draw();
	void next();
	void keyPressed(int key);

	float initTime;
	int initCoins;

};
#endif

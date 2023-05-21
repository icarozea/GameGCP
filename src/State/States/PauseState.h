#ifndef PauseState_h
#define PauseState_h

#include "State.h"
#include "Game.h"
#include "Pedestrian.h"

class PauseState : public State {
public:
	PauseState(Game* game);

	~PauseState() {};
	void update();
	void draw();
	void next();
	float initTime;
	void keyPressed(int key);

	Pedestrian* pedestrian;
};
#endif
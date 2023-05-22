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
	void keyPressed(int key);
	void resetStatus();

	ofTrueTypeFont font;

	float fps = 0;
	int coins = 0;
	float timePaused = 0;
	bool getTime = true;
	bool flash = true;
	float flashTime = 0;
	float flashTimeControl = 0.8f;

	bool showTimer = true;

};
#endif
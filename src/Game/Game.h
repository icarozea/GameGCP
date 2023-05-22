#ifndef Game_h
#define Game_h

#include "ofMain.h"
#include "StateMachine.h"
#include "GameObjectContainer.h"
#include "GameObjectGenerator.h"

class Player;

class Game : public StateMachine {
	ofEasyCam cam;
	Player* player;
	GameObjectContainer* gameObjects = nullptr;
	GameObjectGenerator* generator = nullptr;
	bool bDebug;
	bool bPlayerFinish;
	float initTime;

	ofSoundPlayer scream;
	ofSoundPlayer getingCoin;
	ofSoundPlayer obstacle;
	ofSoundPlayer start;
	ofSoundPlayer shot;
	ofSoundPlayer speed;
	ofSoundPlayer lessCoin;
	ofSoundPlayer oilStation;
	ofSoundPlayer sand;
	ofSoundPlayer crazyArrow;
	ofSoundPlayer moveToStart;


public:
	int ROAD_LENGTH;
	int ROAD_WIDTH;

	Game();
	~Game();
	void init();
	void update();
	void draw();
	void finishGame();
	void toggleDebug();
	bool isFinished();
	void setFinished(bool v);

	Player* getPlayer();
	vector<GameObject*> getCollisions(GameObject* gameObject);
	void addGameObject(GameObject* gameobject);

	float getEllapsedTime();
	void doScreamStartGame();
	void doScream();
	void doScreamGettingCoins();
	void doScreamObstacle();
	void doScreamShot();
	void doScreamSpeed();
	void doScreamLessCoin();
	void doScreamOilStation();
	void doScreamSand();
	void doScreamCrazyArrow();
	void doScreammoveToStart();

};
#endif

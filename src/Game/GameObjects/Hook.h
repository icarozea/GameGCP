#include "GameObject.h"

#include "ofxAssimpModelLoader.h"

class Hook : public GameObject {
	int speed;
	bool bTurned;
	bool turningHook;
	float elapseTurningTime;
public:
	Hook(Game *game, glm::vec3 pos, glm::vec3 dim);
	~Hook();

	void update() override;
	void draw() override;
	void drawDebug() override;
	void setSpeedRotation(int speedIn);
	void updatePosition(int posX, int posY);
	void receiveCarCollision(Player *car);
	ofxAssimpModelLoader model;
};

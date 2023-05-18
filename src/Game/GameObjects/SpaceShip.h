#include "GameObject.h"

#include "ofxAssimpModelLoader.h"

class SpaceShip : public GameObject {
	float speed = -5;
	bool bTurned;
	float elapseTurningTime;
public:
	SpaceShip(Game* game, glm::vec3 pos, glm::vec3 dim);
	~SpaceShip();

	void update() override;
	void draw() override;
	void drawDebug() override;
	void shoot();
	ofxAssimpModelLoader model;
};




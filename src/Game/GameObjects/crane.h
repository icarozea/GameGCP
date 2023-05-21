#include "GameObject.h"

#include "ofxAssimpModelLoader.h"
#define CRANE_RADIUS 365
#define CRANE_Y 300
#define CRANE_Z 30
class Hook;

class Crane : public GameObject {
	float speed = -5;
	int degrees;
	bool bTurned;
	float elapseTurningTime;
protected:
	Hook *hook;
public:
	Crane(Game *game, glm::vec3 pos, glm::vec3 dim);
	~Crane();
	void update() override;
	void draw() override;
	void drawDebug() override;
	void updateHookPosition();
	ofxAssimpModelLoader model;
};

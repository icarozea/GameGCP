#include "GameObject.h"

class SpeedArrow : public GameObject {
	ofPlanePrimitive plane;
	ofTexture texture;
public:
	SpeedArrow(Game *game, glm::vec3 pos, glm::vec3 dim);
	~SpeedArrow();

	void draw() override;
	void drawDebug() override;
	void receiveCarCollision(Player *car) override;

};
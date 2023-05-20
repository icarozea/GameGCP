#include "GameObject.h"

class OilStain : public GameObject {
	ofPlanePrimitive plane;
	ofTexture texture;
public:
	OilStain(Game *game, glm::vec3 pos, glm::vec3 dim);
	~OilStain();

	void draw() override;
	void drawDebug() override;
	void receiveCarCollision(Player *car) override;

};
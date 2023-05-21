#include "GameObject.h"

class Well : public GameObject {
	ofPlanePrimitive plane;
	ofTexture texture;
public:
	Well(Game *game, glm::vec3 pos, glm::vec3 dim);
	~Well();

	void draw() override;
	void drawDebug() override;
	void receiveCarCollision(Player *car) override;

};
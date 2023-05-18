#include "GameObject.h"

class Sand : public GameObject {
	ofPlanePrimitive plane;
	ofTexture texture;
public:
	Sand(Game* game, glm::vec3 pos, glm::vec3 dim);
	~Sand();

	void draw() override;
	void drawDebug() override;
	void receiveCarCollision(Player* car) override;

};
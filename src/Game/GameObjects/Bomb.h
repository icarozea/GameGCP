#pragma once
#include "GameObject.h"

class Bomb : public GameObject {

public:
	Bomb(Game *game, glm::vec3 pos, glm::vec3 dim);
	~Bomb();

	void update() override;
	void draw() override;
	void drawDebug() override;
	void receiveCarCollision(Player *car);

};

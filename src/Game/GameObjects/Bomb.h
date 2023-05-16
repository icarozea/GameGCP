#pragma once
#include "GameObject.h"

class Bomb : public GameObject {

public:
	Bomb(Game *game, ofNode transform);
	~Bomb();

	void update() override;
	void draw() override;
	void checkCollisions() override;

};

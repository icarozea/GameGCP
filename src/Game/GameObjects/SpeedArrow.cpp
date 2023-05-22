#include "SpeedArrow.h"
#include "Player.h"
#include "Game.h"

SpeedArrow::SpeedArrow(Game *game, glm::vec3 pos, glm::vec3 dim, int direction) : GameObject(game, pos, dim) {

	plane.setParent(transform);
	collider->set(dim.x - 400, dim.y - 420, dim.z - 700);
	transform.rotateDeg(-90, 1, 0, 0);
	switch (direction) {
		case 1:
			transform.rotateDeg(-90, 0, 1, 0);
			break;
		case 2:
			transform.rotateDeg(-180, 0, 1, 0);
			break;
		case 3:
			transform.rotateDeg(-90, 0, 1, 0);
			break;
		case 4:
			transform.rotateDeg(-90, 0, 1, 0);
			break;
	}
	
	plane.set(dim.x, dim.z);
	ofEnableNormalizedTexCoords();
	ofDisableArbTex();
	ofImage img;
	img.load("speedArrow.png");

	texture = img.getTexture();

}
SpeedArrow::~SpeedArrow() {}

void SpeedArrow::draw() {

	//collider->drawWireframe();
	//transform.transformGL();
	//ofDrawAxis(100);
	//transform.restoreTransformGL();
	texture.bind();
	plane.draw();
	texture.unbind();
}

void SpeedArrow::receiveCarCollision(Player *car) {
	car->doubleSpeed();
	game->doScreamSpeed();
}


void SpeedArrow::drawDebug() {
	collider->drawWireframe();
	transform.transformGL();
	ofDrawAxis(100);
	transform.restoreTransformGL();
}

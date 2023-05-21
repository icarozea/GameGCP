#include "Well.h"
#include "Player.h"
#include "Game.h"

Well::Well(Game *game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {

	plane.setParent(transform);
	collider->set(dim.x - 750, dim.y - 500, dim.z - 1100);
	transform.rotateDeg(-90, 1, 0, 0);
	//transform.rotateDeg(65, 0, 1, 0);
	plane.set(dim.x, dim.z);
	ofEnableNormalizedTexCoords();
	ofDisableArbTex();
	ofImage img;
	img.load("pozo.png");

	texture = img.getTexture();

}
Well::~Well() {}

void Well::draw() {

	//collider->drawWireframe();
	transform.transformGL();
	//ofDrawAxis(100);
	transform.restoreTransformGL();
	texture.bind();
	plane.draw();
	texture.unbind();
}

void Well::receiveCarCollision(Player *car) {
	car->initPosition();
}


void Well::drawDebug() {
	collider->drawWireframe();
	transform.transformGL();
	ofDrawAxis(100);
	transform.restoreTransformGL();
}

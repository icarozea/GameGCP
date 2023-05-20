#include "OilStain.h"
#include "Player.h"
#include "Game.h"

OilStain::OilStain(Game *game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {

	plane.setParent(transform);
	collider->set(dim.x - 400, dim.y - 120, dim.z - 400);
	transform.rotateDeg(-90, 1, 0, 0);
	plane.set(dim.x, dim.z);
	ofEnableNormalizedTexCoords();
	ofDisableArbTex();
	ofImage img;
	img.load("oil.png");

	texture = img.getTexture();

}
OilStain::~OilStain() {}

void OilStain::draw() {

	collider->drawWireframe();
	transform.transformGL();
	ofDrawAxis(100);
	transform.restoreTransformGL();
	texture.bind();
	plane.draw();
	texture.unbind();
}

void OilStain::receiveCarCollision(Player *car) {
	car->moveCar();
}


void OilStain::drawDebug() {
	collider->drawWireframe();
	transform.transformGL();
	ofDrawAxis(100);
	transform.restoreTransformGL();
}

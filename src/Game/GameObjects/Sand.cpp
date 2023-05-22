#include "Sand.h"
#include "Player.h"
#include "Game.h"

Sand::Sand(Game *game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {

	plane.setParent(transform);
	collider->set(dim.x -600, dim.y - 200, dim.z - 1100);
	transform.rotateDeg(-90, 1, 0, 0);
	transform.rotateDeg(90, 0, 1, 0);
	plane.set(dim.x, dim.z);
	ofEnableNormalizedTexCoords();
	ofDisableArbTex();
	ofImage img;
	img.load("arena2.png");

	texture = img.getTexture();

}
Sand::~Sand() {}

void Sand::draw() {
	
	//collider->drawWireframe();
	//transform.transformGL();
	//ofDrawAxis(100);
	//transform.restoreTransformGL();
	texture.bind();
	plane.draw();
	texture.unbind();
}

void Sand::receiveCarCollision(Player *car) {
	car->reduceSpeed();
	game->doScreamSand();
}


void Sand::drawDebug() {
	collider->drawWireframe();
	transform.transformGL();
	ofDrawAxis(100);
	transform.restoreTransformGL();
}

#include "crane.h"
#include "Player.h"
#include "Game.h"
#include "Hook.h"
#include <cmath>


Crane::Crane(Game *game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
	model.loadModel("Knuckle_Crane2.obj");
	model.setRotation(0, 180, 0, 0, 1);
	//auto crane = new Crane(game,	glm::vec3(0, 100, 300), glm::vec3(200, 50, 300));
	hook = new Hook(game, glm::vec3(pos.x- CRANE_RADIUS, pos.y, pos.z- CRANE_Z), glm::vec3(100, 60, 60));
	game->addGameObject(hook);
	transform.rotateDeg(180, 0, 1, 0);
	model.setScale(0.70, 0.70, 0.70);
	degrees = 0;
	speed = 6;
}
Crane::~Crane() {

}

void Crane::update() {
	model.update();
	this->updateHookPosition();	
};
void Crane::draw() {
	ofEnableDepthTest();
	transform.transformGL();
	model.drawFaces();
	ofDrawAxis(100);
	transform.restoreTransformGL();
	collider->drawWireframe();

};

void Crane::drawDebug() {
	collider->drawDebug();

	transform.transformGL();
	ofDrawAxis(100);
	transform.restoreTransformGL();
}

void Crane::updateHookPosition() {
	transform.rotateDeg(1, 0, 1, 0);
	degrees += 1;
	float radians = (degrees * -1) * PI / 180.0;  // Convertir el ángulo a radianes
	int x = CRANE_RADIUS * cos(radians);
	int y = CRANE_RADIUS * sin(radians);
	hook->updatePosition(transform.getPosition().x - x, transform.getPosition().z - y);

	if (degrees == 360)
		degrees = 0;
}

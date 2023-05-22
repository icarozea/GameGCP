#include "Hook.h"
#include "Player.h"
#include "Game.h"


Hook::Hook(Game *game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
	model.loadModel("hook.obj");
	model.setScale(0.12, 0.12, 0.12);
	transform.rotateDeg(90, 0, 0, 1);
	speed = 2;
	turningHook = false;
}
Hook::~Hook() {

}

void Hook::update() {
	model.update();
	//transform.rotateDeg(5, 0, 1, 0);
	if (transform.getY() == 350 || transform.getY() == 0) {
		if (transform.getY() == 350) {
			turningHook = false;
		}
		speed = speed * -1;
	}
	transform.setPosition(glm::vec3(transform.getX(), transform.getY() + speed, transform.getZ()));

	if (turningHook) {
		transform.rotateDeg(5, 0, 1, 0);
	}
};
void Hook::draw() {
	ofEnableDepthTest();
	transform.transformGL();
	model.drawFaces();
	//ofDrawAxis(100);
	transform.restoreTransformGL();
	//collider->drawWireframe();

};

void Hook::drawDebug() {
	collider->drawDebug();

	transform.transformGL();
	ofDrawAxis(100);
	transform.restoreTransformGL();
}

void Hook::setSpeedRotation(int speedIn) {
	this->speed = speedIn;
}

void Hook::updatePosition(int posX, int posY) {
	transform.setPosition(glm::vec3(posX, transform.getY(), posY));
}

void Hook::receiveCarCollision(Player *car) {
	car->removeAllCoins();
	game->doScreamLessCoin();
	turningHook = true;
}
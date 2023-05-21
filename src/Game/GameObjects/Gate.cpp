#include "Gate.h"
#include "Player.h"
#include "Game.h"


Gate::Gate(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
	material.setEmissiveColor(ofColor::gray);
	transform.rotateDeg(90, 0, 1, 0);
}
Gate::~Gate() {}

void Gate::draw() {

	material.begin();
	{
		transform.transformGL();

		ofDrawBox(-collider->getWidth() / 2, 60, 600, 50, 360, 50);

		//Horizontal
		ofDrawBox(collider->getPosition().x,
			collider->getPosition().y,
			collider->getPosition().z,
			collider->getWidth(),
			collider->getHeight(),
			50);

		ofDrawBox(collider->getWidth() / 2, 60, 600, 50, 360, 50);

		transform.restoreTransformGL();
	}
	material.end();
}

void Gate::drawDebug() {
	collider->drawDebug();
}

void Gate::update()
{
	if (isIncreasing) {
		position = collider->getPosition().y + 1 * 0.5;
		collider->setPosition(0, position, 600);
		if (collider->getPosition().y >= 280) {
			collider->setPosition(0, 280, 600);
			isIncreasing = false;
		}
	}
	else {
		position = collider->getPosition().y - 1 * 0.5;
		collider->setPosition(0, position, 600);
		if (collider->getPosition().y <= 70) {
			collider->setPosition(0, 70, 600);
			isIncreasing = true;
		}
	}
}

void Gate::receiveCarCollision(Player* player)
{
	player->stop();
}

void Gate::receiveBulletCollision(GameObject* bullet)
{
	countShoot += 1;
	if (countShoot >= 5) {
		kill();
	}
}
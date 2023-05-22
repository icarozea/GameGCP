#include "Bomb.h"
#include "Game.h"
#include "Player.h"

Bomb::Bomb(Game *game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim)
{
	material.setEmissiveColor(ofColor::black);
}

Bomb::~Bomb() {}

void Bomb::update() {
	if (transform.getY() < 0) {
		kill();
	}
	transform.move(transform.getYAxis() * -4);
};

void Bomb::draw() {

	material.begin();
	{
		collider->draw();
		//collider->drawDebug();
	}
	material.end();
	//transform.transformGL();
	//ofDrawAxis(100);
	//transform.restoreTransformGL();

};

void Bomb::drawDebug() {
	collider->drawDebug();

	transform.transformGL();
	ofDrawAxis(100);
	transform.restoreTransformGL();
}

void Bomb::receiveCarCollision(Player *car) {
	car->initPosition();
	kill();
}
#include "SpaceShip.h"
#include "Player.h"
#include "Game.h"
#include "Bomb.h"

SpaceShip::SpaceShip(Game *game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
	model.loadModel("Intergalactic_Spaceship.dae");

	collider->move(dim.x, dim.y, dim.z);
	model.setRotation(0, 180, 0, 0, 1);
	
	model.setPosition(0, 300, 0);
	model.setScale(0.50, 0.50, 0.50);
	model.setLoopStateForAllAnimations(OF_LOOP_NORMAL);
	model.playAllAnimations();

	transform.rotateDeg(90, 0, 1, 0);
	speed = 4;
	bTurned = false;
}
SpaceShip::~SpaceShip() {

}

void SpaceShip::update() {
	model.update();
	if ((ofGetElapsedTimef() - elapseTurningTime) > 3) {
		transform.rotateDeg(180, 0, 1, 0);
		elapseTurningTime = ofGetElapsedTimef();
		//this->shoot();
	}
	transform.move(transform.getZAxis() * speed);
	bTurned = false;

};
void SpaceShip::draw() {
	transform.transformGL();
	model.drawFaces();

	ofDrawAxis(200);
	transform.restoreTransformGL();

	collider->drawWireframe();

};

void SpaceShip::shoot() {
	game->addGameObject(new Bomb(game, transform));
}
/*
void Player::drawDebug() {
	collider->drawDebug();

	transform.transformGL();
	ofDrawAxis(100);
	transform.restoreTransformGL();
}*/
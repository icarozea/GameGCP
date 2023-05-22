#include "SpaceShip.h"
#include "Player.h"
#include "Game.h"
#include "Bomb.h"

SpaceShip::SpaceShip(Game *game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
	model.loadModel("Intergalactic_Spaceship.dae");
	model.setRotation(0, 180, 0, 0, 1);
	model.setScale(0.50, 0.50, 0.50);
	model.setLoopStateForAllAnimations(OF_LOOP_NORMAL);
	model.playAllAnimations();
	transform.rotateDeg(90, 0, 1, 0);
	speed = 6;
	elapseTurningTime = ofGetElapsedTimef();
	elapseShootingTime = ofGetElapsedTimef();
	posxInit = pos.x;
}
SpaceShip::~SpaceShip() {

}

void SpaceShip::update() {
	model.update();

	if ((ofGetElapsedTimef() - elapseTurningTime) > 5) {
		transform.rotateDeg(180, 0, 1, 0);
		elapseTurningTime = ofGetElapsedTimef();
	}

	if (transform.getX() > posxInit - 500 && transform.getX() < posxInit - 497) {
		//std::cout << "posxInit1 :" << posxInit - 500 << endl;
		//std::cout << "posxInit2 :" << posxInit - 497 << endl;
		this->game->addGameObject(new Bomb(this->game, transform.getPosition(), glm::vec3(70)));
	}

	transform.move(transform.getZAxis() * speed);

};
void SpaceShip::draw() {
	ofEnableDepthTest();
	transform.transformGL();
	model.drawFaces();
	transform.restoreTransformGL();
	//collider->drawWireframe();

};

void SpaceShip::shoot() {
	
}

void SpaceShip::drawDebug() {
	collider->drawDebug();

	transform.transformGL();
	ofDrawAxis(100);
	transform.restoreTransformGL();
}
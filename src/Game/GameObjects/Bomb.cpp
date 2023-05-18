#include "Bomb.h"
#include "Game.h"

Bomb::Bomb(Game *game, ofNode otherTransform)
	:GameObject(game, otherTransform.getGlobalPosition(), glm::vec3(40))
{
	transform.setGlobalOrientation(otherTransform.getGlobalOrientation());
	material.setEmissiveColor(ofColor::black);
}

Bomb::~Bomb() {}

void Bomb::update() {
	transform.move(transform.getYAxis() * -2);
};

void Bomb::draw() {

	material.begin();
	{
		collider->draw();
	}
	material.end();

};

void Bomb::drawDebug() {
	collider->drawDebug();

	transform.transformGL();
	ofDrawAxis(100);
	transform.restoreTransformGL();
}

void Bomb::checkCollisions() {
	vector<GameObject*> collisions = game->getCollisions(this);
	for (auto c : collisions) {
		c->receiveBulletCollision(this);
	}
}

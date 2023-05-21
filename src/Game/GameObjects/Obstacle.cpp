#include "Obstacle.h"
#include "Player.h"

Obstacle::Obstacle(Game* game, glm::vec3 pos, glm::vec3 dim) :
	GameObject(game, pos) {

	material.setDiffuseColor(ofColor::darkGreen);
	collider->setPosition(pos);
	collider->set(dim.x, dim.y, dim.z);
}

Obstacle::~Obstacle()
{
}

void Obstacle::update()
{
}


void Obstacle::draw()
{
	material.begin();
	{
		collider->draw();
	}
	material.end();
}

void Obstacle::drawDebug()
{
	collider->drawWireframe();
}

void Obstacle::receiveCarCollision(Player* player)
{
	player->stop();
}

void Obstacle::receiveBulletCollision(GameObject* bullet)
{
	this->kill();
	bullet->kill();
}
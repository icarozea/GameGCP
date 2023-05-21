#include "Obstacle.h"
#include "Player.h"

Obstacle::Obstacle(Game* game, glm::vec3 pos, glm::vec3 dim) :
	GameObject(game, pos, dim) {

	material.setDiffuseColor(ofColor::darkGreen);
	//collider->setPosition(pos);
	//collider->set(dim.x, dim.y, dim.z);
	fbo.allocate(400, 400);
	ofLoadImage(texture, "piedra.png");
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
		texture.bind();
		collider->draw();
		cone.draw();
		texture.unbind();
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
#include "CrazyBow.h"
#include "Player.h"
#include "Game.h"

CrazyBow::CrazyBow(Game* game, glm::vec3 pos, glm::vec3 dim) :
	GameObject(game, pos, dim) {
	material.setDiffuseColor(ofColor::white);

	//collider->setPosition(pos);
	//collider->set(dim.x, dim.y, dim.z);

	interval = 10.0f;
	randomValue = ofRandom(47);

	ofDisableArbTex();
	ofEnableNormalizedTexCoords();

	fbo.allocate(400, 400);
	halfCircle.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
	int numVertices = 50;
	float radius = 180.0f;
	float angleStep = 180.0f / (numVertices - 1);
	float angle = 0.0f;
	halfCircle.addVertex(ofVec3f(0, 0, 0));
	for (int i = 0; i < numVertices; i++) {
		float x = radius * cos(ofDegToRad(angle));
		float y = radius * sin(ofDegToRad(angle));
		halfCircle.addVertex(ofVec3f(x, y, 0));
		angle += angleStep;
	}

	font.load("verdana.ttf", 55, true, true);
}

CrazyBow::~CrazyBow()
{
}

void CrazyBow::setup()
{
}

void CrazyBow::update()
{
	fbo.begin();
	{
		ofBackground(255, 24, 215);
		timer += ofGetLastFrameTime();
		if (timer >= interval) {
			timer = 0;
			getCoin = true;
			randomValue = updateRandomNumber();

			ofSetColor(255);
			numbers = ofToString(randomValue);
			font.drawString(ofToString(randomValue), collider->getPosition().x, collider->getPosition().y);

		}
	}
	fbo.end();
}

void CrazyBow::draw()
{
	material.begin();
	{
		//collider->drawWireframe();
		fbo.getTexture().bind();
		{
			ofPushMatrix();
			ofTranslate(collider->getPosition().x + 700, collider->getPosition().y, collider->getGlobalPosition().z);
			ofSetColor(255);
			halfCircle.draw();
			ofPopMatrix();
		}
		fbo.getTexture().unbind();
	}
	material.end();
}

void CrazyBow::drawDebug()
{
	collider->drawDebug();

}

void CrazyBow::receiveCarCollision(Player* player)
{
	if (getCoin) {
		player->addCoins(randomValue);
		getCoin = false;
		game->doScreamCrazyArrow();
	}
}

int CrazyBow::updateRandomNumber() {
	int random = ofRandom(3, 85);
	return random;
}
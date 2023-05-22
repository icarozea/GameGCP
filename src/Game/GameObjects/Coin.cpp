#include "Coin.h"
#include "Player.h"
#include "Game.h"


Coin::Coin(Game *game, glm::vec3 pos, glm::vec3 dim):GameObject(game, pos, dim) {
    material.setDiffuseColor(ofColor::yellow);
	//fbo.allocate(400, 400);
	//ofLoadImage(texture, "moneda.jpg");
}
Coin::~Coin(){
    
}


void Coin::update(){
    model.update();
}

void Coin::draw(){
    
    material.begin();
    {
		//texture.bind();
		collider->draw();
		//texture.unbind();
    }
    material.end();
}

void Coin::drawDebug() {
	collider->drawDebug();

	transform.transformGL();
	ofDrawAxis(100);
	transform.restoreTransformGL();
}

void Coin::receiveCarCollision(Player *car){
    car->addCoins(5);
	game->doScreamGettingCoins();
    kill();
}

void Coin::receiveBulletCollision(GameObject *bullet){
    bullet->kill();
    kill();
    //game->getPlayer()->addCoins(1000);
}

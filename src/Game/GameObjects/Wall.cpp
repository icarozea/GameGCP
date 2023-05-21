#include "Wall.h"
#include "Player.h"
#include "Pedestrian.h"

Wall::Wall(Game *game, glm::vec3 pos, glm::vec3 dim, int numRoad): GameObject(game, pos, dim){
    material.setEmissiveColor(ofColor::darkorange);
	if (numRoad == 3 || numRoad == 4)
		transform.rotateDeg(90, 0, 1, 0);
}
Wall::~Wall(){}

void Wall::draw(){
    
    material.begin();
    {
        collider->draw();
    }
    material.end();
}



void  Wall::receiveCarCollision(Player *car){
    car->stop();
}

void  Wall::receiveBulletCollision(GameObject *bullet){
    bullet->kill();
};

void Wall::receivePedestrianCollision(Pedestrian *pedestrian){
   pedestrian->turn();
}

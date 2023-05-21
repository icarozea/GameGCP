

#include "Road.h"
#include "Game.h"

Road::Road(Game *game, glm::vec3 pos, glm::vec3 dim, int numRoad): GameObject(game, pos){
    material.setDiffuseColor(ofColor::darkGrey);
    
    plane.setParent(transform);
    transform.rotateDeg(-90, 1, 0, 0);
    plane.set(dim.x, dim.z);
	lights = getLightsRoad(pos, numRoad);

	if (numRoad == 3 || numRoad == 4)
		transform.rotateDeg(90, 0, 1, 0);

	for (auto light : lights) {
		light.setDiffuseColor(ofColor::white);
	}
    
}
Road::~Road(){}

void Road::draw(){
    
	for (auto light : lights) {
		light.enable();
	}
    material.begin();
    {
        plane.draw();
    }
    material.end();
}


void Road::drawDebug(){
    plane.drawWireframe();
}

vector<ofLight> Road::getLightsRoad(glm::vec3 pos, int numRoad) {
	vector<ofLight> lightsRoad;
	if (numRoad == 1 || numRoad == 2) {
		ofLight light2;
		light2.setPosition(pos.x + 200, 200, pos.z);
		lightsRoad.push_back(light2);
	}
	else if (numRoad == 3 || numRoad == 4) {
		ofLight light;
		light.setPosition(pos.x, 250 - pos.y, pos.z);
		lightsRoad.push_back(light);
	}
	return lightsRoad;
}

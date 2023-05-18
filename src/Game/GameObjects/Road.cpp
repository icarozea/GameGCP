#include "Road.h"
#include "Game.h"

Road::Road(Game *game, glm::vec3 pos, glm::vec3 dim): GameObject(game, pos){
    material.setDiffuseColor(ofColor::darkGrey);
    
    plane.setParent(transform);
    transform.rotateDeg(-90, 1, 0, 0);
    plane.set(dim.x, dim.z);
    
    light.setPosition(200, 200, 200);
    light2.setPosition(200, 200, 7200);
    light3.setPosition(200, 200, 14200);
    light.setDiffuseColor(ofColor::white);
    light2.setDiffuseColor(ofColor::white);
    light3.setDiffuseColor(ofColor::white);
}
Road::~Road(){}

void Road::draw(){
    
    light.enable();
    light2.enable();
    light3.enable();
    material.begin();
    {
        plane.draw();
    }
    material.end();
}


void Road::drawDebug(){
    plane.drawWireframe();
}

#pragma once
#include "GameObject.h"
#ifndef Gate_h
#define Gate_h
class Gate: public GameObject {

public: 
	Gate(Game* game, glm::vec3 pos, glm::vec3 dim);
    ~Gate();

    void draw() override;
    void drawDebug() override;
    void update() override;
    void receiveCarCollision(Player* player) override;
    void receiveBulletCollision(GameObject* bullet) override;

    bool isIncreasing = true;
    float position = 25;
    int countShoot = 0;
};

#endif /* Gate_h */


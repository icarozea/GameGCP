#pragma once
#include "GameObject.h"

class CrazyBow : public GameObject
{
public:
	CrazyBow(Game* game, glm::vec3 pos, glm::vec3 dim);
	~CrazyBow();

    void setup();
    void draw() override;
    void drawDebug() override;
    void update() override;
    void receiveCarCollision(Player* player) override;
    int updateRandomNumber();

    ofFbo fbo;
    ofLight light;
    ofEasyCam cam;
    ofBoxPrimitive bow;
    
    bool getCoin = true;
    int randomValue;

    ofTrueTypeFont font;

    float timer = 0;
    float interval;
    string numbers;
};

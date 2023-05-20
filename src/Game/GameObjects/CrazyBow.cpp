#include "CrazyBow.h"
#include "Player.h"

CrazyBow::CrazyBow(Game* game, glm::vec3 pos, glm::vec3 dim) :
    GameObject(game, pos, dim) {
    material.setDiffuseColor(ofColor::white);

    collider->setPosition(pos);
    collider->set(dim.x, dim.y, dim.z);

    interval = 10.0f;
    randomValue = ofRandom(47);
    
    ofDisableArbTex();
    ofEnableNormalizedTexCoords();
   
    fbo.allocate(400, 400);
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
        ofBackground(255);
        timer += ofGetLastFrameTime();
        if (timer >= interval) {
            timer = 0;
            getCoin = true;
            randomValue = updateRandomNumber();

            //std::cout << "Get Coin? " << getCoin << " | Value: " << randomValue << endl;

            numbers = ofToString(randomValue);
            ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
            font.drawString(ofToString(randomValue), collider->getPosition().x + 250, collider->getPosition().y);

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
            ofTranslate(collider->getPosition().x + 250, collider->getPosition().y - 30, 800);

            ofPath path;
            path.arc(0, 0, 100, 100, 0, 180);
            path.setCircleResolution(50);
            path.setFilled(true);

            path.getTessellation().draw();

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
    }
}

int CrazyBow::updateRandomNumber() {
    int random = ofRandom(3, 85);
    return random;
}

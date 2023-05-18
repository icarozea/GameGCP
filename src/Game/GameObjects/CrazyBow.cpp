#include "CrazyBow.h"
#include "Player.h"

CrazyBow::CrazyBow(Game* game, glm::vec3 pos, glm::vec3 dim) :
    GameObject(game, pos, dim) {
    collider->setPosition(pos);
    collider->set(dim.x, dim.y, dim.z);
    //std::cout << collider->getPosition() << endl;

    randomValue = ofRandom(0, 100);
    material.setDiffuseColor(ofColor::white);

    interval = 10.0f;
    randomValue = ofRandom(47);

    fbo.allocate(400, 400, GL_RGBA);
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
        //ofBackground(255);
        for (int i = 0; i < 100; i++) {
            ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
            ofDrawCircle(ofRandom(400), ofRandom(400), 10);
        }
    }
    fbo.end();

    timer += ofGetLastFrameTime();
    //std::cout << "Timer: " << timer;
    if (timer >= interval) {
        randomValue = updateRandomNumber();
        getCoin = true;
        std::cout << "Get Coin? "<< getCoin << " | Value: " << randomValue << endl;
        
        timer = 0;
    }

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

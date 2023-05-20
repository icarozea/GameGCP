#include "PlayState.h"
#include "ResultState.h"
#include "Player.h"
#include "PauseState.h"

PlayState::PlayState(Game *game, float currentTime, float coins): State(game, "Play State"){
    initTime = currentTime;
    initCoins = coins;
    game->init();
};

void PlayState::update(){
    game->update();
    
    if(ofGetKeyPressed(OF_KEY_LEFT))
        game->getPlayer()->steerLeft();
    if(ofGetKeyPressed(OF_KEY_RIGHT))
        game->getPlayer()->steerRight();
    if(ofGetKeyPressed(OF_KEY_UP))
        game->getPlayer()->accelerate();
    if(ofGetKeyPressed(OF_KEY_DOWN))
        game->getPlayer()->brake();
};
    
void PlayState::draw(){
    ofBackground(0);
    ofPushMatrix();
    {
        ofTranslate(10, 0);
        ofTranslate(0, 20);
        ofDrawBitmapString("Fps: " + ofToString(ofGetFrameRate()), 0, 0);
        ofTranslate(0, 20);
        ofDrawBitmapString(name, 0, 0);
        ofTranslate(0, 20);
        ofDrawBitmapString("Time: " + ofToString(initTime + game->getEllapsedTime(), 2), 0, 0);
        ofTranslate(0, 20);
        ofDrawBitmapString("Speed: " + ofToString(game->getPlayer()->getSpeed(), 2), 0, 0);
        ofTranslate(0, 20);
        ofDrawBitmapString("Coins: " + ofToString(initCoins + game->getPlayer()->getCoins(), 2), 0, 0);

    }
    ofPopMatrix();
    game->draw();
};

void PlayState::next(){
    game->setState(new ResultState(game));
};


void PlayState::keyPressed(int key){
    if(key == 'l')
        game->getPlayer()->toggleLight();
    if(key == 'd')
        game->toggleDebug();
    if(key == 's')
        game->getPlayer()->shoot();
    if (key == 'p')
        game->setState(new PauseState(game));
}

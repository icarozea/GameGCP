#include "PauseState.h"
#include "ResultState.h"
#include "Player.h"
#include "PlayState.h"

PauseState::PauseState(Game* game) : State(game, "Pause State") {
	font.load("sans-serif", 80, true, true);
	timePaused = game->getEllapsedTime();
	std::cout << game->getEllapsedTime();
	coins = game->getPlayer()->getCoins();
	fps = ofGetFrameRate();
}

void PauseState::update() {
	if (getTime) {
		getTime = false;
	}
	flashTime += ofGetLastFrameTime();
	if (flashTime >= flashTimeControl) {
		flashTime = 0;
		flash = !flash;
	}

}

void PauseState::draw() {
	ofBackground(0);
	ofPushMatrix();
	{
		ofTranslate(10, 0);
		ofTranslate(0, 20);
		ofDrawBitmapString("Fps: " + ofToString(fps), 0, 0);
		ofTranslate(0, 20);
		ofDrawBitmapString(name, 0, 0);
		ofTranslate(0, 20);
		ofDrawBitmapString("Time: " + ofToString(timePaused, 2), 0, 0);
		ofTranslate(0, 20);
		ofDrawBitmapString("Speed: " + ofToString(0, 2), 0, 0);
		ofTranslate(0, 20);
		ofDrawBitmapString("Coins: " + ofToString(coins, 2), 0, 0);
		if (flash) {
			font.drawString("PAUSE", ofGetWidth() * 0.4, ofGetHeight() * 0.4);
		}

		game->getPlayer()->stop();
	}
	ofPopMatrix();
}

void PauseState::next() {
}

void PauseState::keyPressed(int key) {
	if (key == 'p') {
		game->setState(new PlayState(game, timePaused, coins));
		//std::cout << " | Time " << timePaused;
		//resetStatus();
	}
}

void PauseState::resetStatus() {
	getTime = true;
	coins = 0;
	timePaused = 0;
}

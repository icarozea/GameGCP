#include "Game.h"
#include "Player.h"

Game::Game() {
	// TODO create settings
	ROAD_WIDTH = 2000;
	ROAD_LENGTH = 10000;

	generator = new GameObjectGenerator(this);
	bDebug = false;
	scream.load("aaa.wav");
	getingCoin.load("getCoin.wav");
	obstacle.load("collider.wav");
	start.load("fondo1.mp3");
	start.setVolume(0.05f);
	shot.load("shot.mp3");
	speed.load("speed.mp3");
	lessCoin.load("lessCoin.mp3");
	oilStation.load("oilStation.mp3");
	sand.load("sand.mp3");
	crazyArrow.load("crazyArrow.wav");
	moveToStart.load("moveStart.mp3");
}

Game::~Game() {
	ofLogNotice() << "Deleting game";
	delete gameObjects;
	delete generator;
	delete currentState();
}

void Game::init() {

	if (gameObjects != nullptr)
		delete gameObjects;


	gameObjects = new GameObjectContainer();

	player = new Player(this);
	player->init();

	cam.setPosition(0, 300, -600);
	cam.setTarget(player->transform);
	cam.setParent(player->transform);
	//cam.disableMouseInput();
	cam.setFarClip(100000);

	gameObjects->add(player);
	generator->generateWorld();
	bPlayerFinish = false;
	initTime = ofGetElapsedTimef();
}

void Game::update() {
	gameObjects->update();
}

void Game::draw() {
	ofEnableLighting();
	ofEnableDepthTest();

	cam.begin();
	{
		if (bDebug) gameObjects->drawDebug();
		else gameObjects->draw();
	}
	cam.end();

	ofDisableLighting();
	ofDisableDepthTest();
}


Player* Game::getPlayer() {
	return player;
}

vector<GameObject*> Game::getCollisions(GameObject* gameObject) {
	return gameObjects->getCollisions(gameObject);
}

void  Game::addGameObject(GameObject* gameobject) {
	gameObjects->add(gameobject);
}

void Game::finishGame() {
	bPlayerFinish = true;
}

void Game::toggleDebug() {
	bDebug = !bDebug;
}

bool Game::isFinished() {
	return bPlayerFinish;
}

void Game::setFinished(bool v) {
	bPlayerFinish = v;
}

float Game::getEllapsedTime() {
	return ofGetElapsedTimef() - initTime;
}

void Game::doScreamStartGame()
{
	start.play();
}

void Game::doScream() {
	scream.play();
}

void Game::doScreamGettingCoins()
{
	getingCoin.play();
}

void Game::doScreamObstacle()
{
	obstacle.play();
}

void Game::doScreamShot()
{
	shot.play();
}

void Game::doScreamSpeed()
{
	speed.play();
}

void Game::doScreamLessCoin()
{
	lessCoin.play();
}

void Game::doScreamOilStation()
{
	oilStation.play();
}

void Game::doScreamSand()
{
	sand.play();
}

void Game::doScreamCrazyArrow()
{
	crazyArrow.play();
}

void Game::doScreammoveToStart()
{
	moveToStart.play();
}

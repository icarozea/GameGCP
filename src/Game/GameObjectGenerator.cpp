
#include "GameObjectGenerator.h"
#include "Game.h"
#include "Road.h"
#include "Wall.h"
#include "Goal.h"
#include "Coin.h"
#include "Pedestrian.h"
#include "SpaceShip.h"
#include "Sand.h"
#include "OilStain.h"
#include "Well.h"
#include "crane.h"
#include "Hook.h"
#include "SpeedArrow.h"
#include "CrazyBow.h"
#include "Gate.h"
#include "Obstacle.h"

GameObjectGenerator::GameObjectGenerator(Game *game): game(game){}

void GameObjectGenerator::generateWorld(){
    int W = game->ROAD_WIDTH;
    int L = game->ROAD_LENGTH;

	int LSR = 10000;
	int wallSize = 100;

	
	//Road 1 and things
    glm::vec3 roadPosition(0, -50.1, L/2 - 1000);
    auto road1 = new Road(game, roadPosition, glm::vec3(W, 0, L), 1);	
	game->addGameObject(road1);

	auto wall_1 = new Wall(game,
		glm::vec3(W / 2, roadPosition.y, roadPosition.z + 500),
		glm::vec3(wallSize, wallSize, L + 1000), 1);
	game->addGameObject(wall_1);

	auto wall_2 = new Wall(game,
		glm::vec3(-W / 2, roadPosition.y, roadPosition.z + 500),
		glm::vec3(wallSize, wallSize, L - 3000), 1);
	game->addGameObject(wall_2);

	auto coin = new Coin(game,
		glm::vec3(0, -25, 500), glm::vec3(50));

	auto coin2 = new Coin(game,
		glm::vec3(0, -25, 600), glm::vec3(50));

	game->addGameObject(coin);
	game->addGameObject(coin2);

	auto pedestrian = new Pedestrian(game,
		glm::vec3(roadPosition.x + (W / 2 - 100), -25, roadPosition.z / 2), glm::vec3(50, 150, 50));
	game->addGameObject(pedestrian);

	auto spaceShip = new SpaceShip(game,
		glm::vec3(roadPosition.x + (W / 2) - 500, 300, (roadPosition.z / 2) + 2000), glm::vec3(200, 50, 300));

	game->addGameObject(spaceShip);

	auto obst = new Obstacle(game,
		glm::vec3(roadPosition.x - 500, 100, roadPosition.z + 1500), glm::vec3(400));

	auto obst11 = new Obstacle(game,
		glm::vec3(roadPosition.x + 500, 100, roadPosition.z - 1000), glm::vec3(400));

	game->addGameObject(obst);
	game->addGameObject(obst11);

	auto sand = new Sand(game,
		glm::vec3((W / 2) - 500, -48.5, 7200), glm::vec3(1200));

	game->addGameObject(sand);

	auto speedArrow = new SpeedArrow(game,
		glm::vec3((W / 2) - 1400, -48.5, roadPosition.z + 2000), glm::vec3(800));

	game->addGameObject(speedArrow);

	auto oilStain = new OilStain(game,
		glm::vec3((W / 2) - 1100, -48.5, 1500), glm::vec3(1000));

	game->addGameObject(oilStain);

	auto crazyBow = new CrazyBow(game,
		glm::vec3(W / 8, 15, 400),
		glm::vec3(180, 55, 50));
	game->addGameObject(crazyBow);
	
	//Road 2 and things
	glm::vec3 roadPosition2(-8000, -50.1, L / 2 - 1000);
	auto road2 = new Road(game, roadPosition2, glm::vec3(W, 0, L), 2);
	game->addGameObject(road2);

	auto wall_3 = new Wall(game,
		glm::vec3(roadPosition2.x + (W / 2), roadPosition2.y, roadPosition2.z + 500),
		glm::vec3(wallSize, wallSize, L - 3000), 2);
	game->addGameObject(wall_3);
	auto wall_4 = new Wall(game,
		glm::vec3(roadPosition2.x - (W / 2), roadPosition.y, roadPosition.z + 500),
		glm::vec3(wallSize, wallSize, L + 1000), 2);
	game->addGameObject(wall_4);

	auto pedestrian2 = new Pedestrian(game,
		glm::vec3(roadPosition2.x + (W / 2 - 100), -25, roadPosition2.z / 2), glm::vec3(50, 150, 50));
	game->addGameObject(pedestrian2);

	//auto spaceShip2 = new SpaceShip(game,
	//glm::vec3(roadPosition2.x + (W / 2) - 500, 300, (roadPosition2.z / 2) + 2000), glm::vec3(200, 50, 300));
	//game->addGameObject(spaceShip2);

	auto obst2 = new Obstacle(game,
		glm::vec3(roadPosition2.x - 500, 100, roadPosition.z), glm::vec3(400));

	auto obst22 = new Obstacle(game,
		glm::vec3(roadPosition2.x + 500, 100, roadPosition.z - 2000), glm::vec3(400));

	game->addGameObject(obst2);
	game->addGameObject(obst22);


	//Road 3 and things
	glm::vec3 roadPosition3(-4000, -50.1, L - 1000);
	auto road3 = new Road(game, roadPosition3, glm::vec3(W, 0, LSR), 3);
	game->addGameObject(road3);

	auto wall_5 = new Wall(game,
		glm::vec3(roadPosition3.x, roadPosition3.y, roadPosition3.z + (W / 2)),
		glm::vec3(wallSize, wallSize, LSR), 3);
	game->addGameObject(wall_5);
	auto wall_6 = new Wall(game,
		glm::vec3(roadPosition3.x, roadPosition3.y, roadPosition3.z - (W / 2)),
		glm::vec3(wallSize, wallSize, LSR - 4000), 3);
	game->addGameObject(wall_6);

	auto crane = new Crane(game,
		glm::vec3(roadPosition3.x, 50, roadPosition3.z), glm::vec3(200, 50, 300));

	game->addGameObject(crane);

	auto obst3 = new Obstacle(game,
		glm::vec3(roadPosition3.x, -25, roadPosition3.z), glm::vec3(200));

	auto obst33 = new Obstacle(game,
		glm::vec3(roadPosition3.x - 2000, 100, roadPosition3.z + 500), glm::vec3(400));

	game->addGameObject(obst3);
	game->addGameObject(obst33);

	//Road 4 and things
	glm::vec3 roadPosition4(-4000, -50.1, 0);
	auto road4 = new Road(game, roadPosition4, glm::vec3(W, 0, LSR), 4);
	game->addGameObject(road4);
    
	auto wall_7 = new Wall(game,
		glm::vec3(roadPosition4.x, roadPosition4.y, roadPosition4.z + (W / 2)),
		glm::vec3(wallSize, wallSize, LSR - 4000), 4);
	game->addGameObject(wall_7);
	auto wall_8 = new Wall(game,
		glm::vec3(roadPosition4.x, roadPosition4.y, roadPosition4.z - (W / 2)),
		glm::vec3(wallSize, wallSize, LSR), 4);
	game->addGameObject(wall_8);
	
	auto goal = new Goal(game,
		glm::vec3(-W / 2, roadPosition.y, 0),
		glm::vec3(W, 100, 100));
	goal->isFixed = true;
	game->addGameObject(goal);

	auto well = new Well(game,
		glm::vec3(roadPosition4.x - 1000, -48.5, roadPosition4.z + 400), glm::vec3(1200));

	game->addGameObject(well);

	auto gate = new Gate(game,
		glm::vec3(roadPosition4.x - 1000, 65, roadPosition4.z - 400),
		glm::vec3(W / 2 - 200, 350, 50));
	game->addGameObject(gate);

	auto obst4 = new Obstacle(game,
		glm::vec3(roadPosition4.x + 1000, 100, roadPosition4.z - 500), glm::vec3(400));
	game->addGameObject(obst4);

	

}


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

GameObjectGenerator::GameObjectGenerator(Game *game): game(game){}

void GameObjectGenerator::generateWorld(){
    int W = game->ROAD_WIDTH;
    int L = game->ROAD_LENGTH;

	int LSR = 10000;

	

    glm::vec3 roadPosition(0, -50.1, L/2 - 1000);
    auto road1 = new Road(game, roadPosition, glm::vec3(W, 0, L), 1);
	glm::vec3 roadPosition2(-8000, -50.1, L / 2 - 1000);
	auto road2 = new Road(game, roadPosition2, glm::vec3(W, 0, L), 2);
	glm::vec3 roadPosition3(-4000, -50.1, L - 1000);
	auto road3 = new Road(game, roadPosition3, glm::vec3(W, 0, LSR), 3);
	glm::vec3 roadPosition4(-4000, -50.1, 0);
	auto road4 = new Road(game, roadPosition4, glm::vec3(W, 0, LSR), 4);
    
    game->addGameObject(road1);
	game->addGameObject(road2);
	game->addGameObject(road3);
	game->addGameObject(road4);

//
    int wallSize = 100;
	auto wall_1 = new Wall(game,
		glm::vec3(W / 2, roadPosition.y, roadPosition.z + 500),
		glm::vec3(wallSize, wallSize, L + 1000), 1);
	game->addGameObject(wall_1);

    auto wall_2 = new Wall(game,
                    glm::vec3(-W/2, roadPosition.y, roadPosition.z + 500),
                           glm::vec3(wallSize, wallSize, L-3000), 1);
    game->addGameObject(wall_2);

	auto wall_3 = new Wall(game,
		glm::vec3(roadPosition2.x +(W / 2), roadPosition2.y, roadPosition2.z + 500),
		glm::vec3(wallSize, wallSize, L - 3000), 2);
	game->addGameObject(wall_3);


	auto wall_4 = new Wall(game,
		glm::vec3(roadPosition2.x - (W / 2), roadPosition.y, roadPosition.z + 500),
		glm::vec3(wallSize, wallSize, L + 1000), 2);
	game->addGameObject(wall_4);

	auto wall_5 = new Wall(game,
		glm::vec3(roadPosition3.x, roadPosition3.y, roadPosition3.z + (W / 2)),
		glm::vec3(wallSize, wallSize, LSR), 3);
	game->addGameObject(wall_5);

	auto wall_6 = new Wall(game,
		glm::vec3(roadPosition3.x, roadPosition3.y, roadPosition3.z - (W / 2)),
		glm::vec3(wallSize, wallSize, LSR - 4000), 3);
	game->addGameObject(wall_6);

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
    
    
    auto coin = new Coin(game,
        glm::vec3(0, -25, 500), glm::vec3(50));

	auto coin2 = new Coin(game,
		glm::vec3(0, -25, 600), glm::vec3(50));
    
    game->addGameObject(coin);
	game->addGameObject(coin2);
    
    
    auto pedestrian = new Pedestrian(game,
        glm::vec3(W/2 - 100, -25, 500), glm::vec3(50, 150, 50));

	auto pedestrian2 = new Pedestrian(game,
		glm::vec3(W / 2 - 200, -25, 700), glm::vec3(50, 150, 50));
	/*for (int i = 0; i < 10; i++) {
		auto pedestrian = new Pedestrian(game,
			glm::vec3(W / 2 - 100 - 25 * i, -25, 300 * (i + 1)), glm::vec3(50, 150, 50));
		game->addGameObject(pedestrian2);
	}*/

   
	//game->addGameObject(pedestrian2);

	auto spaceShip = new SpaceShip(game,
		glm::vec3((W / 2) - 500, 300, 900), glm::vec3(200, 50, 300));

	game->addGameObject(spaceShip);

	auto sand = new Sand(game, 
		glm::vec3((W / 2) - 500, -48.5, 7200), glm::vec3(800));

	game->addGameObject(sand);

	auto speedArrow = new SpeedArrow(game,
		glm::vec3((W / 2) - 1400, -48.5, 7200), glm::vec3(800));

	game->addGameObject(speedArrow);

	auto oilStain = new OilStain(game,
		glm::vec3((W / 2) - 1100, -48.5,1500), glm::vec3(500));

	game->addGameObject(oilStain);

	auto well = new Well(game,
		glm::vec3((W / 2) - 1400, -48.5, 3500), glm::vec3(1200));

	game->addGameObject(well);

	//auto hook = new Hook(game, glm::vec3(0, -25, 600), glm::vec3(200));

	auto crane = new Crane(game,
		glm::vec3(0, 50, 5000), glm::vec3(200, 50, 300));
	
	game->addGameObject(crane);
	

}


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
    
    glm::vec3 roadPosition(0, -50.1, L/2 - 1000);
    auto road = new Road(game, roadPosition, glm::vec3(W, 0, L));
    
    game->addGameObject(road);

//
    int wallSize = 100;


    //for(int x = 0; x < w; x++){
    //    for(int y = 0; y < h; y++){
    //        if(circuito.getColor(x, y).a > 250){

    //            auto wall = new Wall(game,
    //                            glm::vec3(x*wallSize - 5000, roadPos.y, y*wallSize -2000),
    //                            glm::vec3(wallSize*0.99));
    //            game->addGameObject(wall);
    //        }
    //    }
    //}

    
     //wall with parts
    /*for(int l = 0; l < l; l += wallsize){
        auto wall_r = new wall(game,
                        glm::vec3(-w/2, roadpos.y, l - 1000 + wallsize/2),
                        glm::vec3(wallsize));

        wall_r->isfixed = true;
        game->addgameobject(wall_r);

    }*/
    
    
    auto wall_r = new Wall(game,
                    glm::vec3(-W/2, roadPosition.y, roadPosition.z),
                           glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_r);

    /*wall_r = new Wall(game,
                    glm::vec3(-W/2, roadPos.y, roadPos.z - L * 0.8),
                           glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_r);*/

    

    auto wall_l = new Wall(game,
                    glm::vec3(W/2, roadPosition.y, roadPosition.z),
                           glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_l);

   /* wall_l = new Wall(game,
                    glm::vec3(W/2, roadPos.y, roadPos.z - L * 0.8),
                           glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_l);*/

    auto goal = new Goal(game,
                    glm::vec3(0, roadPosition.y, roadPosition.z + L/2),
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

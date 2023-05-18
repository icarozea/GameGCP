
#include "GameObjectGenerator.h"
#include "Game.h"
#include "Road.h"
#include "Wall.h"
#include "Goal.h"
#include "Coin.h"
#include "Gate.h"
#include "Obstacle.h"
#include "Bullet.h"
#include "Pedestrian.h"
#include "CrazyBow.h"
#include "SpaceShip.h"
#include "Sand.h"

GameObjectGenerator::GameObjectGenerator(Game *game): game(game){}

void GameObjectGenerator::generateWorld(){
    int W = game->ROAD_WIDTH;
    int L = game->ROAD_LENGTH;
    
    glm::vec3 roadPos(0, -50.1, L/2 - 1000);
    auto road = new Road(game, roadPos, glm::vec3(W, 0, L));
    
    game->addGameObject(road);
//
    int wallSize = 100;
    
    ofNode node;
    node.setGlobalPosition(18, 55, 22);

    ofImage circuito;
    circuito.load("circuito.png");

    int w = circuito.getWidth()/16;
    int h = circuito.getHeight()/16;
    circuito.resize(w, h);


//    for(int x = 0; x < w; x++){
//        for(int y = 0; y < h; y++){
//            if(circuito.getColor(x, y).a > 250){
//                  auto wall = new Wall(game,
//                               glm::vec3(x*wallSize - 5000, roadPos.y, y*wallSize -2000),
//                               glm::vec3(wallSize*0.99));
//              game->addGameObject(wall);
//           }
//      }
//    }
   
//    WALL with parts
//    for(int l = 0; l < L; l += wallSize){
//        auto wall_r = new Wall(game,
//                       glm::vec3(-W/2, roadPos.y, l - 1000 + wallSize/2),
//                        glm::vec3(wallSize));
//
//        wall_r->isFixed = true;
//        game->addGameObject(wall_r);
//
//    }
    
    
    auto wall_r = new Wall(game,
                    glm::vec3(-W/2, roadPos.y, roadPos.z),
                           glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_r);

    wall_r = new Wall(game,
                    glm::vec3(-W/2, roadPos.y, roadPos.z - L * 0.8),
                           glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_r);
    

    auto wall_l = new Wall(game,
                    glm::vec3(W/2, roadPos.y, roadPos.z),
                           glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_l);

    wall_l = new Wall(game,
                    glm::vec3(W/2, roadPos.y, roadPos.z - L * 0.8),
                           glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_l);
//
    auto goal = new Goal(game,
                    glm::vec3(0, roadPos.y, roadPos.z + L/2),
                           glm::vec3(W, 100, 100));
    goal->isFixed = true;
    game->addGameObject(goal);
    
    
    auto coin = new Coin(game,
        glm::vec3(0, -25, 500), glm::vec3(50));
    
    game->addGameObject(coin);
 
    
    auto pedestrian = new Pedestrian(game,
        glm::vec3(W/2 - 100, -25, 500), glm::vec3(50, 150, 50));

    game->addGameObject(pedestrian);


    auto obst = new Obstacle(game,
        glm::vec3(0, 0, 750), glm::vec3(50));
    
    game->addGameObject(obst);

    auto bullet = new Bullet(game, node);

    game->addGameObject(bullet);

    auto gate = new Gate(game,
        glm::vec3(0, 65, 600),
        glm::vec3(W / 2 - 200, 350, 50));
    game->addGameObject(gate);

    auto crazyBow = new CrazyBow(game,
        glm::vec3(W / 8, 15, 400),
        glm::vec3(180,55,50));
    game->addGameObject(crazyBow);

    auto spaceShip = new SpaceShip(game,
        glm::vec3((W / 2) - 500, 300, 900), glm::vec3(200, 50, 300));
    game->addGameObject(spaceShip);

    auto sand = new Sand(game,
        glm::vec3((W / 2) - 500, -48.5, 7200), glm::vec3(800));
    game->addGameObject(sand);
}

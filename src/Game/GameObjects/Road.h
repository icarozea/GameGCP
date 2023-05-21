#ifndef Road_h
#define Road_h

#include "GameObject.h"

class Road : public GameObject{
    
	vector<ofLight> lights;
    ofPlanePrimitive plane;
public:
    Road(Game *game, glm::vec3 pos, glm::vec3 dim, int numRoad);
    ~Road();
    
    void draw() override;
    void drawDebug() override;
	vector<ofLight> getLightsRoad(glm::vec3 pos, int numRoad);
    
};

#endif /* Road_h */

//
// Created by jacob on 26.01.2024.
//

#ifndef RAYLIBSTARTER_MAP_H
#define RAYLIBSTARTER_MAP_H


#include <vector>
#include "raylib.h"
#include "Entity.h"

class Map {
public:
    void drawMap();
    void drawCollisions();
    void update();
private:
    std::vector<Entity*> entities;
    int collisionData[16][12];
    std::vector<Rectangle> collisionRectangles;
    Texture2D mapTextureForeground;
    Texture2D mapTextureBackground;
    void generateCollisionRectangles(); //should be called just once
    std::vector<int> enemySpawnQueue;
    void generateEnemySpawnQueue();
    int mapLevel = 0;
    enum {preparing, playing, finished}state;
    int calcSpawnCD();
    int calcMaxEnemies();
    int countEnemies();
    int timeUntilNextSpawn = 0;
};


#endif //RAYLIBSTARTER_MAP_H

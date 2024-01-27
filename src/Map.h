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
    void init();
private:
    std::vector<Entity*> entities;
    int collisionData[16][12];
    std::vector<Rectangle> collisionRectangles;
    Texture2D mapTextureForeground = LoadTexture("assets/grahics/backgrounds/bg.png");
    Texture2D mapTextureBackground;
    std::vector<int> enemySpawnQueue;
    void generateEnemySpawnQueue();
    Image collisionImage = LoadImage("assets/graphics/backgrunds/collision.png");
    int mapLevel = 0;
    enum {preparing, playing, finished}state;
    int calcSpawnCD();
    int calcMaxEnemies();
    int countEnemies();
    int timeUntilNextSpawn = 0;
};


#endif //RAYLIBSTARTER_MAP_H

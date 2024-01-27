//
// Created by jacob on 26.01.2024.
//

#include "Map.h"
#include "WalkingEnemy.h"
#include "JumpingEnemy.h"

void Map::generateEnemySpawnQueue() {
    //generate a random number of enemies to spawn relative to the map level
    //1 is a karen, 2 is a dog
    int enemyCostPool = 1 + mapLevel * 2;
    while (enemyCostPool > 0) {
        int enemyCost = GetRandomValue(1, 2);
        enemySpawnQueue.push_back(enemyCost);
        enemyCostPool -= enemyCost;
    }

}

int Map::calcSpawnCD() {
    //by default, the spawn CD is 5 seconds
    float spawnCD = 300;
    //spawns occur 5% faster for map Level
    spawnCD /= (1 + mapLevel * 0.05f);
    return int(spawnCD);
}

int Map::calcMaxEnemies() {
    //by default the max enemies on the map is 3, and it increases by 1 every 2 levels
    return 3 + mapLevel / 2;
}

int Map::countEnemies() {
    //go through all entities and count the enemies
    int enemyCount = 0;
    for (int i= 0; i < entities.size(); ++i) {
        if (dynamic_cast<WalkingEnemy*>(entities[i]) != nullptr) {
            enemyCount++;
        }
        if (dynamic_cast<JumpingEnemy*>(entities[i]) != nullptr) {
            enemyCount++;
        }
    }
    return enemyCount;
}

void Map::init() {
    collisionRectangles.push_back({-16,32,102,8}); //top left
    collisionRectangles.push_back({202,32,102,8}); //top right
    collisionRectangles.push_back({88,88,112,8}); //center floating
    collisionRectangles.push_back({-16,94,48,8}); //left mini
    collisionRectangles.push_back({256,96,48,8}); //right mini
    collisionRectangles.push_back({-16,144,104,8}); //bottom left
    collisionRectangles.push_back({200,144,104,8}); //bottom right
    collisionRectangles.push_back({-16,200,320,16}); //ground



}

void Map::drawMap() {
    DrawTexture(mapTextureBackground, 0, 0, WHITE);
    DrawTexture(mapTextureForeground, 0, 0, WHITE);
}

void Map::drawCollisions() {
    for (Rectangle& r : collisionRectangles) {
        DrawRectangleLines(r.x, r.y, r.width, r.height, RED);
    }

}

void Map::update() {
    //TODO
}

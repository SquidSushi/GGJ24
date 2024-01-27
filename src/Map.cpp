//
// Created by jacob on 26.01.2024.
//

#include "Map.h"
#include "WalkingEnemy.h"
#include "JumpingEnemy.h"

void Map::generateEnemySpawnQueue() {


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

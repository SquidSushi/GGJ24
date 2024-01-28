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
    for (unsigned int i = 0; i < entities.size(); ++i) {
        if (dynamic_cast<WalkingEnemy *>(entities[i]) != nullptr) {
            enemyCount++;
        }
        if (dynamic_cast<JumpingEnemy *>(entities[i]) != nullptr) {
            enemyCount++;
        }
    }
    return enemyCount;
}

void Map::init() {
    collisionRectangles.push_back({-16, 32, 102, 8}); //top left
    collisionRectangles.push_back({202, 32, 102, 8}); //top right
    collisionRectangles.push_back({88, 88, 112, 8}); //center floating
    collisionRectangles.push_back({-16, 94, 48, 8}); //left mini
    collisionRectangles.push_back({256, 96, 48, 8}); //right mini
    collisionRectangles.push_back({-16, 144, 104, 8}); //bottom left
    collisionRectangles.push_back({200, 144, 104, 8}); //bottom right
    collisionRectangles.push_back({-16, 192, 320, 16}); //ground
    this->mapLevel = 10;
    generateEnemySpawnQueue();
    timeUntilNextSpawn = calcSpawnCD();
}

void Map::drawMap() {
    DrawTexture(mapTextureBackground, 0, 0, WHITE);
    for (auto it = entities.begin(); it != entities.end(); ++it) {
        (*it)->animation(frameCount);
    }
    DrawTexture(mapTextureForeground, 0, 0, WHITE);
}

void Map::drawCollisions() {
    for (Rectangle &r: collisionRectangles) {
        DrawRectangleLines(
                (int) r.x,
                (int) r.y,
                (int) r.width,
                (int) r.height,
                RED);
    }
    for (auto it = entities.begin(); it != entities.end(); ++it) {
        (*it)->drawDebug();
    }

}

void Map::update() {
    frameCount++;
    //collide all Entities with all collision rectangles and note
    for (auto &entity: entities) {
        entity->collisionRec.x = entity->position.x;
        entity->collisionRec.y = entity->position.y;

        Rectangle feet = {entity->position.x,
                          entity->position.y + entity->collisionRec.height - 4,
                          entity->collisionRec.width,
                          4};
        Rectangle head = {
                entity->position.x,
                entity->position.y + 4,
                entity->collisionRec.width,
                4
        };
        entity->collisions = 0;
        for (auto collisionRectangle: collisionRectangles) {
            if (CheckCollisionRecs(feet, collisionRectangle)) {
                float depth = GetCollisionRec(feet, collisionRectangle).height;
                entity->position.y -= depth;
                entity->collisions += 1;
                entity->position.y += 1 / 128.0f;
            }
            if (CheckCollisionRecs(head, collisionRectangle)) {
                float depth = GetCollisionRec(head, collisionRectangle).height;
                entity->position.y += depth;
                entity->collisions += 2;
            }
        }
    }
    for (unsigned int i = 0; i < entities.size(); ++i) {
        entities[i]->update(frameCount);
    }
    timeUntilNextSpawn--;
    //spawn enemies
    if (timeUntilNextSpawn <= 0) {
        if (enemySpawnQueue.size() > 0 && countEnemies() < calcMaxEnemies()) {
            int enemyCost = enemySpawnQueue[0];
            enemySpawnQueue.erase(enemySpawnQueue.begin());
            if (enemyCost == 1) {
                entities.push_back(new WalkingEnemy());
                entities[entities.size() - 1]->position = {
                        static_cast<float>(GetRandomValue(0, 288),
                                -32)
                };

            }
            if (enemyCost == 2) {
                entities.push_back(new JumpingEnemy());
                entities[entities.size() - 1]->position = {
                        static_cast<float>(GetRandomValue(0, 288),
                                -32)
                };
            }
        }
        timeUntilNextSpawn = calcSpawnCD();
    }


    //delete entities that are out marked to be deleted
    for (unsigned int i = 0; i < entities.size(); ++i) {
        if (entities[i]->toBeDeleted) {
            delete entities[i];
            entities.erase(entities.begin() + i);
        }
    }
}

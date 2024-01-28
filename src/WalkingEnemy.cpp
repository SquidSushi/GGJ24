//
// Created by jacob on 26.01.2024.
//

#include "WalkingEnemy.h"
#include "enumsAndConstants.h"

WalkingEnemy::WalkingEnemy() {
    position = {0,0};
    velocity = {0.25,0};
    sourceRec = {0, 0, 32, 32};
    collisionRec = {position.x, position.y, 16, 32};
    direction = Left;
}

void WalkingEnemy::walking() {
    switch (direction) {
        case Left:
            sourceRec = {sourceRec.x,sourceRec.y,-32,32};
            velocity.x = -0.25;
            break;
        case Right:
            sourceRec = {sourceRec.x,sourceRec.y,32,32};
            velocity.x = 0.25;
            break;
        default:
            break;
    }
}

void WalkingEnemy::update(int frameCount_p) {
    handleCollision();
    walking();
    handleGravity();
    wrapAroundScreen();
    transformPosition();
}

void WalkingEnemy::animation(int frameCount_p) {
    for (int i = 0; i < 3; i++){
        DrawTexturePro(walkingTexture, {currentFrame * 32.0f,0,sourceRec.width, sourceRec.height}, {position.x + i * 288 - 288 - 8, position.y - 9, 32, 32+8}, {}, 0, WHITE);
    }
    if(frameCount_p % 10 == 0){
        currentFrame++;
    }
}

void WalkingEnemy::updateState() {

}

void WalkingEnemy::drawDebug() {
    Entity::drawDebug();
    DrawRectangleLinesEx(collisionRec, 1, RED);
}

void WalkingEnemy::handleCollision() {
    if (collisions & 3){
        velocity.y = 0;
        updateState();
    }
}

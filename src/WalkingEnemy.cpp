//
// Created by jacob on 26.01.2024.
//

#include "WalkingEnemy.h"

WalkingEnemy::WalkingEnemy() {
    position = {0,0};
    velocity = {1,0};
    sourceRec = {0, 0, 32, 32};
    state = Left;
}

void WalkingEnemy::walking() {
    switch (state) {
        case Left:
            sourceRec = {sourceRec.x,sourceRec.y,-32,32};
            velocity.x = -2;
            break;
        case Right:
            sourceRec = {sourceRec.x,sourceRec.y,32,32};
            velocity.x = 2;
            break;
        default:
            break;
    }
}

void WalkingEnemy::update() {
    walking();
    handleGravity();
    wrapAroundScreen();
    transformPosition();
}

void WalkingEnemy::animation(int frameCount_p) {
    for (int i = 0; i < 3; i++){
        DrawTexturePro(walkingTexture, {currentFrame * 32.0f,0,sourceRec.width, sourceRec.height}, {position.x + i * 256 - 256 - 8, position.y, 32, 32+8}, {}, 0, WHITE);
    }
    if(frameCount_p % 10 == 0){
        currentFrame++;
    }
}

void WalkingEnemy::updateState() {

}

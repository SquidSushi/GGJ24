//
// Created by jacob on 26.01.2024.
//

#include "JumpingEnemy.h"
#include "enumsAndConstants.h"

JumpingEnemy::JumpingEnemy() {
    position = {0,0};
    velocity = {0,0};
    sourceRec = {0, 0, 32, 32};
    collisionRec = {position.x, position.y, 16, 32};
    direction = Right;
    state = Waiting;
}

void JumpingEnemy::update(int frameCount_p) {
    handleCollision();
    jumping(frameCount_p);
    handleGravity();
    wrapAroundScreen();
    transformPosition();
}

void JumpingEnemy::animation(int frameCount_p) {
    switch (state) {
        case Waiting:
            animateWaiting(frameCount_p);
            break;
        case Jumping:
            animateJumping(frameCount_p);
            break;
        case Slipping:
            animateSlipping(frameCount_p);
            break;
        case Yeeting:
            animateYeeting(frameCount_p);
            break;
        default:
            animateWaiting(frameCount_p);
            break;
    }
}

void JumpingEnemy::updateState() {
    if(direction == Left){
        sourceRec.width = -32;
    }
    else{
        sourceRec.width = 32;
    }
    state = Waiting;
}

void JumpingEnemy::jumping(int frameCount_p) {
    switch(state){
        case JumpingStart:
            velocity.y = -jumpForce;
            if(direction == Left){
                velocity.x = jumpForce * -1;
            }
            else{
                velocity.x = jumpForce;
            }

            state = Jumping;
            break;
        case Waiting:
            velocity.x = 0;
            if(frameCount_p % 60 == 0 && frameCount_p != 0){
                state = JumpingStart;
                position.y -= 2;
            }
            break;
        default:
            break;
    }
}

void JumpingEnemy::animateWaiting(int frameCount_p) {
    for (int i = 0; i < 3; i++){
        DrawTexturePro(standingTexture, {currentFrame * 32.0f,0,sourceRec.width, sourceRec.height}, {position.x + i * 288 - 288 - 8, position.y - 9, 16+16, 32+8}, {}, 0, WHITE);
    }
    if(frameCount_p % 10 == 0){
        currentFrame++;
    }
}

void JumpingEnemy::animateJumping(int frameCount_p) {
    for (int i = 0; i < 3; i++){
        DrawTexturePro(jumpingTexture, {currentFrame * 32.0f,0,sourceRec.width, sourceRec.height}, {position.x + i * 288 - 288 - 8, position.y - 9, 32, 32+8}, {}, 0, WHITE);
    }
    if(frameCount_p % 10 == 0){
        currentFrame++;
    }
}

void JumpingEnemy::animateSlipping(int frameCount_p) {
    for (int i = 0; i < 3; i++){
        DrawTexturePro(slippingTexture, {currentFrame * 32.0f,0,sourceRec.width, sourceRec.height}, {position.x + i * 288 - 288 - 8, position.y - 9, 32, 32+8}, {}, 0, WHITE);
    }
    if(frameCount_p % 10 == 0){
        currentFrame++;
    }
}

void JumpingEnemy::animateYeeting(int frameCount_p) {
    for (int i = 0; i < 3; i++){
        DrawTexturePro(yeetingTexture, {currentFrame * 32.0f,0,sourceRec.width, sourceRec.height}, {position.x + i * 288 - 288 - 8, position.y - 9, 16+16, 32+8}, {}, 0, WHITE);
    }
    if(frameCount_p % 10 == 0){
        currentFrame++;
    }
}

void JumpingEnemy::drawDebug() {
    Entity::drawDebug();
    DrawRectangleLinesEx(collisionRec, 1, RED);
}

void JumpingEnemy::handleCollision() {
    if (collisions & 3){
        velocity.y = 0;
        if (collisions & 1){
            updateState();
        }
    }
}

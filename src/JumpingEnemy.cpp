//
// Created by jacob on 26.01.2024.
//

#include "JumpingEnemy.h"
#include "enumsAndConstants.h"

JumpingEnemy::JumpingEnemy() {
    position = {0,0};
    velocity = {0,0};
    sourceRec = {0, 0, 32, 32};
    state = Waiting;
}

void JumpingEnemy::update(int frameCount_p) {
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
            }
            break;
        default:
            break;
    }
}

void JumpingEnemy::animateWaiting(int frameCount_p) {
    for (int i = 0; i < 3; i++){
        DrawTexturePro(standingTexture, {currentFrame * 32.0f,0,sourceRec.width, sourceRec.height + 8}, {position.x + i * 256 - 256 - 8, position.y, 16+16, 32+16}, {}, 0, WHITE);
    }
    if(frameCount_p % 10 == 0){
        currentFrame++;
    }
}

void JumpingEnemy::animateJumping(int frameCount_p) {
    for (int i = 0; i < 3; i++){
        DrawTexturePro(jumpingTexture, {currentFrame * 32.0f,0,sourceRec.width, sourceRec.height + 8}, {position.x + i * 256 - 256 - 8, position.y, 16+16, 32+16}, {}, 0, WHITE);
    }
    if(frameCount_p % 10 == 0){
        currentFrame++;
    }
}

void JumpingEnemy::animateSlipping(int frameCount_p) {
    for (int i = 0; i < 3; i++){
        DrawTexturePro(slippingTexture, {currentFrame * 32.0f,0,sourceRec.width, sourceRec.height + 8}, {position.x + i * 256 - 256 - 8, position.y, 16+16, 32+16}, {}, 0, WHITE);
    }
    if(frameCount_p % 10 == 0){
        currentFrame++;
    }
}

void JumpingEnemy::animateYeeting(int frameCount_p) {
    for (int i = 0; i < 3; i++){
        DrawTexturePro(yeetingTexture, {currentFrame * 32.0f,0,sourceRec.width, sourceRec.height + 8}, {position.x + i * 256 - 256 - 8, position.y, 16+16, 32+16}, {}, 0, WHITE);
    }
    if(frameCount_p % 10 == 0){
        currentFrame++;
    }
}
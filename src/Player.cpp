//
// Created by jacob on 26.01.2024.
//

#include "Player.h"
#include "enumsAndConstants.h"

//Default Constructor
Player::Player(Vector2 _position, Rectangle _sourceRec) {
    idleAnimation = LoadTexture("assets/graphics/cat/idle.png");
    walkingAnimation = LoadTexture("assets/graphics/cat/walk.png");
    jumpingAnimation = LoadTexture("assets/graphics/cat/jumping.png");
    fallingAnimation = LoadTexture("assets/graphics/cat/falling.png");
    slidingAnimation = LoadTexture("assets/graphics/cat/idle.png");
    position = _position;
    sourceRec = _sourceRec;
}


void Player::PlayerMovement()
{
    if(pressedLeft())
    {
        if(velocity.x > maxSpeed * -1)
        velocity.x -= 0.25;
        if(velocity.x > 0 && state != Jumping && state != Falling){
            state = Sliding;
        }
        if(velocity.x < 0 && state != Jumping && state != Falling){
            state = Walking;
        }
    }
    if(pressedRight())
    {
        if(velocity.x < maxSpeed){
            if(velocity.x < 0 && state != Jumping && state != Falling){
                state = Sliding;
            }
            velocity.x += 0.25;
        }
        if(velocity.x > 0 && state != Jumping && state != Falling){
            state = Walking;
        }
    }
    if(!pressedRight() && !pressedLeft() && state != Jumping && state != Falling){
        velocity.x *= 0.75;
        if(velocity.x < 1 && velocity.x > -1){
            state = Idle;
        }
    }
    if(pressedJump() && state != Jumping && state != Falling)
    {
        velocity.y -= jumpForce;
        state = Jumping;
    }
}

bool Player::pressedLeft() {
    if(IsKeyDown(KEY_A) ||IsKeyDown(KEY_LEFT) || GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X) < -0.5)
    {
        sourceRec.width = -32;
        return true;
    }
    return false;
}

bool Player::pressedRight() {
    if(IsKeyDown(KEY_D) ||IsKeyDown(KEY_RIGHT) || GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_X) > 0.5)
    {
        sourceRec.width = 32;
        return true;
    }
    return false;
}

bool Player::pressedJump() {
    if(IsKeyPressed(KEY_SPACE) ||IsKeyPressed(KEY_Y) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN))
    {
        return true;
    }
    return false;
}

void Player::update() {
    handleGravity();
    wrapAroundScreen();
    transformPosition();
}

void Player::animation(int frameCount_p) {
    switch(this->state){
        case Idle:
            animateIdle(frameCount_p);
            break;
        case Walking:
            animateWalking(frameCount_p);
            break;
        case Sliding:
            animateSliding(frameCount_p);
            break;
        case Jumping:
            animateJumping(frameCount_p);
            break;
        case Falling:
            animateFalling(frameCount_p);
        default:
            break;
    }
}

void Player::animateIdle(int frameCount_p) {
    for (int i = 0; i < 3; i++){
        DrawTexturePro(idleAnimation, {currentFrame * 32.0f,0,sourceRec.width, sourceRec.height + 8}, {position.x + i * 256 - 256 - 8, position.y, 16+16, 32+16}, {}, 0, WHITE);
    }
    if(frameCount_p % 10 == 0){
        currentFrame++;
    }
}

void Player::animateWalking(int frameCount_p) {
    for (int i = 0; i < 3; i++){
        DrawTexturePro(walkingAnimation, {currentFrame * 32.0f,0,sourceRec.width, sourceRec.height + 8}, {position.x + i * 256 - 256 - 8, position.y, 16+16, 32+16}, {}, 0, WHITE);
    }
    if(frameCount_p % 10 == 0){
        currentFrame++;
    }
}

void Player::animateJumping(int frameCount_p) {
    for (int i = 0; i < 3; i++){
        DrawTexturePro(jumpingAnimation, {currentFrame * 32.0f,0,sourceRec.width, sourceRec.height + 8}, {position.x + i * 256 - 256 - 8, position.y, 16+16, 32+16}, {}, 0, WHITE);
    }
    if(frameCount_p % 10 == 0){
        currentFrame++;
    }
}

void Player::animateSliding(int frameCount_p) {
    for (int i = 0; i < 3; i++){
        DrawTexturePro(slidingAnimation, {currentFrame * 32.0f,0,sourceRec.width, sourceRec.height + 8}, {position.x + i * 256 - 256 - 8, position.y, 16+16, 32+16}, {}, 0, WHITE);
    }
    if(frameCount_p % 10 == 0){
        currentFrame++;
    }
}

void Player::animateFalling(int frameCount_p){
    for (int i = 0; i < 3; i++){
        DrawTexturePro(fallingAnimation, {currentFrame * 32.0f,0,sourceRec.width, sourceRec.height + 16}, {position.x + i * 256 - 256 - 8, position.y, 16+16, 32+16}, {}, 0, WHITE);
    }
    if(frameCount_p % 10 == 0){
        currentFrame++;
    }
}
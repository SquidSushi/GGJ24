//
// Created by jacob on 26.01.2024.
//

#include "Player.h"
#include "enumsAndConstants.h"

//Default Constructor
Player::Player(Vector2 _position, Rectangle _sourceRec) {
    for(int i = 0; i < 3; i++){
        idleAnimation[i] = LoadTexture(TextFormat("assets/graphics/cat/Idle_%i.png", i));
        walkingAnimation[i] = LoadTexture(TextFormat("assets/graphics/cat/Walk_%i.png", i));
        jumpingAnimation[i] = LoadTexture(TextFormat("assets/graphics/cat/Jump_%i.png", i));
        fallingAnimation[i] = LoadTexture(TextFormat("assets/graphics/cat/Falling_%i.png", i));
        pivotAnimation[i] = LoadTexture(TextFormat("assets/graphics/cat/Slipping_%i.png", i));
    }
    position = _position;
    sourceRec = _sourceRec;
    collisionRec = {position.x, position.y, 16, 32};
}



void Player::PlayerMovement()
{
    if(pressedLeft())
    {
        if(velocity.x > maxSpeed * -1) {
            velocity.x -= 0.125;
            if (velocity.x < 0 && state != Jumping && state != Falling) {
                state = Walking;
            }
            if (velocity.x > 0 && state != Jumping && state != Falling) {
                state = Sliding;
            }
        }
    }
    if(pressedRight())
    {
        if(velocity.x < maxSpeed){
            if(velocity.x < 0 && state != Jumping && state != Falling){
                state = Sliding;
            }
            velocity.x += 0.125;
        }
        if(velocity.x > 0 && state != Jumping && state != Falling){
            state = Walking;
        }
    }
    if(!pressedRight() && !pressedLeft()){
        velocity.x *= 0.75;
        if(velocity.x < 1 && velocity.x > -1 && state != Jumping && state != Falling){
            state = Idle;
        }
    }
    if(pressedJump() && state != Jumping && state != Falling)
    {
        position.y -= 1;
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

void Player::update(int frameCount_p) {
    if(state == Jumping || state == Falling || state == Walking){
        handleGravity();
    }
    handleCollision();
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
        DrawTexturePro(idleAnimation[powerUpState], {currentFrame * 32.0f,0,sourceRec.width, sourceRec.height + 8}, {position.x + i * 256 - 256 - 8, position.y-8, 16+16, 32+16}, {}, 0, WHITE);
    }
    if(frameCount_p % 10 == 0){
        currentFrame++;
    }
}

void Player::animateWalking(int frameCount_p) {
    for (int i = 0; i < 3; i++){
        DrawTexturePro(walkingAnimation[powerUpState], {currentFrame * 32.0f,0,sourceRec.width, sourceRec.height + 8}, {position.x + i * 256 - 256 - 8, position.y-8, 16+16, 32+16}, {}, 0, WHITE);
    }
    if(frameCount_p % 10 == 0){
        currentFrame++;
    }
}

void Player::animateJumping(int frameCount_p) {
    for (int i = 0; i < 3; i++){
        DrawTexturePro(jumpingAnimation[powerUpState], {currentFrame * 32.0f,0,sourceRec.width, sourceRec.height + 8}, {position.x + i * 256 - 256 - 8, position.y-8, 16+16, 32+16}, {}, 0, WHITE);
    }
    if(frameCount_p % 10 == 0){
        currentFrame++;
    }
}

void Player::animateSliding(int frameCount_p) {
    for (int i = 0; i < 3; i++){
        DrawTexturePro(pivotAnimation[powerUpState], {currentFrame * 32.0f, 0, sourceRec.width, sourceRec.height + 8}, {position.x + i * 256 - 256 - 8, position.y-8, 16 + 16, 32 + 16}, {}, 0, WHITE);
    }
    if(frameCount_p % 10 == 0){
        currentFrame++;
    }
}

void Player::animateFalling(int frameCount_p){
    for (int i = 0; i < 3; i++){
        DrawTexturePro(fallingAnimation[powerUpState], {currentFrame * 32.0f,0,sourceRec.width, sourceRec.height + 8}, {position.x + i * 256 - 256 - 8, position.y - 8, 16+16, 32+16}, {}, 0, WHITE);
    }
    if(frameCount_p % 10 == 0){
        currentFrame++;
    }
}

void Player::updateState() {
    if(pressedLeft())
    {
        if (velocity.x < 0) {
            state = Walking;
        }
        if (velocity.x > 0) {
            state = Sliding;
        }
    }
    if(pressedRight())
    {
        if(velocity.x < maxSpeed){
            if(velocity.x < 0){
                state = Sliding;
            }
        }
        if(velocity.x > 0){
            state = Walking;
        }
    }
    if(!pressedRight() && !pressedLeft()){
        if(velocity.x < 1 && velocity.x > -1){
            state = Idle;
        }
    }
}

void Player::handleCollision() {
    if(state == Jumping || state == Falling){
        if (collisions & 3){
            velocity.y = 0;
            if (collisions & 1){
                updateState();
            }
            if (collisions & 2){
                state = Falling;
            }
        }
    }
}

void Player::drawDebug() {
    Entity::drawDebug();
    DrawRectangleLinesEx(collisionRec, 1, RED);
}

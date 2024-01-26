//
// Created by jacob on 26.01.2024.
//

#include "Player.h"

//Default Constructor
Player::Player(Texture2D _entityTexture, Vector2 _position, Rectangle _sourceRec) {
    entityTexture = _entityTexture;
    position = _position;
    sourceRec = _sourceRec;
}


void Player::PlayerMovement()
{
    if(pressedLeft())
    {
        if(velocity.x > maxSpeed * -1)
        velocity.x -= 1;
        if(velocity.x > 0){
            state = Sliding;
        }
        if(velocity.x < 0){
            state = Walking;
        }
    }
    if(pressedRight())
    {
        if(velocity.x < maxSpeed){
            if(velocity.x < 0){
                state = Sliding;
            }
            velocity.x += 1;
        }
        if(velocity.x > 0){
            state = Walking;
        }
    }
    if(!pressedRight() && !pressedLeft() && state != Jumping && state != Falling){
        velocity.x *= 0.5;
        if(velocity.x < 1){
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
        return true;
    }
    return false;
}

bool Player::pressedRight() {
    if(IsKeyDown(KEY_D) ||IsKeyDown(KEY_RIGHT) || GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_X) > 0.5)
    {
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
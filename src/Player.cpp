//
// Created by jacob on 26.01.2024.
//

#include <valarray>
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
        if(abs(velocity.x) < maxSpeed)
        velocity.x -= 1;
    }
    if(pressedRight())
    {
        if(velocity.x < maxSpeed)
        velocity.x += 1;
    }
    if(!pressedRight() && !pressedLeft()){
        velocity.x *= 0.5;
    }
    if(pressedJump())
    {

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
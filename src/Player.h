//
// Created by jacob on 26.01.2024.
//

#ifndef RAYLIBSTARTER_PLAYER_H
#define RAYLIBSTARTER_PLAYER_H
#include "Entity.h"

class Player : public Entity {
public:
    float jumpForce = 3.35;
    int powerUpState = 0;
    enum powerUpStates{None, Banana, Panty};
    int lives = 0;
    Texture2D idleAnimation[3];
    Texture2D walkingAnimation[3];
    Texture2D jumpingAnimation[3];
    Texture2D fallingAnimation[3];
    Texture2D pivotAnimation[3];

    void PlayerMovement();
    bool pressedLeft();
    bool pressedRight();
    bool pressedJump();
    void update(int frameCount_p) override;
    void animateIdle(int frameCount_p);
    void animateWalking(int frameCount_p);
    void animateJumping(int frameCount_p);
    void animateSliding(int frameCount_p);
    void animateFalling(int frameCount_p);
    void animation(int frameCount_p) override;
    void updateState() override;
    Player(Vector2 _position, Rectangle _sourceRec);
    void drawDebug() override;

    void handleCollision();
};


#endif //RAYLIBSTARTER_PLAYER_H

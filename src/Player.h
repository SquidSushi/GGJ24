//
// Created by jacob on 26.01.2024.
//

#ifndef RAYLIBSTARTER_PLAYER_H
#define RAYLIBSTARTER_PLAYER_H
#include "Entity.h"

class Player : public Entity {
public:
    float jumpForce = 20;
    int lives = 0;
    Texture2D idleAnimation;
    Texture2D walkingAnimation;
    Texture2D jumpingAnimation;
    Texture2D slidingAnimation;

    void PlayerMovement();
    bool pressedLeft();
    bool pressedRight();
    bool pressedJump();
    void update() override;
    void animateIdle(int frameCount_p);
    void animateWalking(int frameCount_p);
    void animateJumping(int frameCount_p);
    void animateSliding(int frameCount_p);
    void animation(int frameCount_p) override;
    Player(Vector2 _position, Rectangle _sourceRec);
};


#endif //RAYLIBSTARTER_PLAYER_H

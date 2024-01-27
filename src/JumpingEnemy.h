//
// Created by jacob on 26.01.2024.
//

#ifndef RAYLIBSTARTER_JUMPINGENEMY_H
#define RAYLIBSTARTER_JUMPINGENEMY_H


#include "Entity.h"

class JumpingEnemy : public Entity {
    enum {Waiting, JumpingStart, Jumping, Slipping, Yeeting} state;
    float jumpForce = 10;
    Texture2D standingTexture = LoadTexture("assets/graphics/dog/DogIdle.png");
    Texture2D jumpingTexture = LoadTexture("assets/graphics/dog/DogWalk.png");
    Texture2D slippingTexture = LoadTexture("assets/graphics/dog/Dog Die.png");
    Texture2D yeetingTexture = LoadTexture("assets/graphics/dog/Dog Die.png");
    int frameCount = 0;
    int direction = 0;
    void jumping(int frameCount_p);
    void updateState() override;
    void animateWaiting(int frameCount_p);
    void animateJumping(int frameCount_p);
    void animateSlipping(int frameCount_p);
    void animateYeeting(int frameCount_p);

public:
    JumpingEnemy();
    void update(int frameCount_p) override;
    void animation(int frameCount_p) override;
};


#endif //RAYLIBSTARTER_JUMPINGENEMY_H

//
// Created by jacob on 26.01.2024.
//

#ifndef RAYLIBSTARTER_ENTITY_H
#define RAYLIBSTARTER_ENTITY_H


#include "raylib.h"

class Entity {
public:
    Vector2 position;
    Vector2 velocity = {0,0};
    float maxSpeed = 10;
    float terminalVelocity = 50;
    float massGravity = 5;
    Texture2D entityTexture;
    Rectangle sourceRec;
    int currentFrame = 0;
    int state = 0;
    enum states{Idle = 0, Walking = 1, Running = 2, Sliding = 3, Jumping = 4, Falling = 5, Laying = 6, Throwing = 7};

    void handleGravity();
    void wrapAroundScreen();
    void transformPosition();
    bool checkForCollision(Vector2 nextPosition);
    void animation(int frameCount_p);
};


#endif //RAYLIBSTARTER_ENTITY_H

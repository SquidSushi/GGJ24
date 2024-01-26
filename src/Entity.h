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
    int state;
    enum states{Idle = 0, Walking = 1, Running = 2, Sliding = 3, Jumping = 4, Laying = 5};

    void handleGravity();
    void wrapAroundScreen();
    void transformPosition();
    bool checkForCollision(Vector2 nextPosition);
    void animation(int frameCount_p);
};


#endif //RAYLIBSTARTER_ENTITY_H

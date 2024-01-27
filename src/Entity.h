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
    float maxSpeed = 5;
    float terminalVelocity = 10;
    float massGravity = 2.5;
    Texture2D entityTexture;
    Rectangle sourceRec;
    int currentFrame = 0;
    int state = 0;

    void handleGravity();
    void wrapAroundScreen();
    void transformPosition();
    bool checkForCollision(Vector2 nextPosition);
     virtual void animation(int frameCount_p) = 0;
    virtual void update() = 0;

    virtual void updateState() = 0;
};


#endif //RAYLIBSTARTER_ENTITY_H

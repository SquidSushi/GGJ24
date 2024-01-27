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
    float maxSpeed = 2;
    float terminalVelocity = 3;
    float massGravity = 0.1;
    Texture2D entityTexture;
    Rectangle sourceRec;
    Rectangle collisionRec = {0,0,16,24};
    int currentFrame = 0;
    int state = 0;
    char collisions;

    void handleGravity();
    void wrapAroundScreen();
    void transformPosition();
     virtual void animation(int frameCount_p) = 0;
     virtual void drawDebug();
    virtual void update(int frameCount_p) = 0;

    virtual void updateState() = 0;

};


#endif //RAYLIBSTARTER_ENTITY_H

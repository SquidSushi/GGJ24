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
    float terminalVelocity;
    float massGravity;
    Texture2D entityTexture;
    Rectangle sourceRec;

    void handleGravity();
    void transformPosition();
    bool checkForCollision(Vector2 nextPosition);
};


#endif //RAYLIBSTARTER_ENTITY_H

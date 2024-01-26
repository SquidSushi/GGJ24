//
// Created by jacob on 26.01.2024.
//

#ifndef RAYLIBSTARTER_JUMPINGENEMY_H
#define RAYLIBSTARTER_JUMPINGENEMY_H


#include "Entity.h"

class JumpingEnemy : public Entity {
    enum {Waiting, Jumping, Slipping, Yeeting} state;
    Texture2D standingTexture;
    Texture2D jumpingTexture;
    Texture2D slippingTexture;
    Texture2D yeetingTexture;
    int frameCount = 0;

};


#endif //RAYLIBSTARTER_JUMPINGENEMY_H

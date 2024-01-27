//
// Created by jacob on 26.01.2024.
//

#ifndef RAYLIBSTARTER_WALKINGENEMY_H
#define RAYLIBSTARTER_WALKINGENEMY_H


#include "Entity.h"

class WalkingEnemy : public Entity {
    enum {Walking, Slipping, Yeeting} state;
    Texture2D walkingTexture = LoadTexture("assets/graphics/dog/DogWalk.png");
    Texture2D slippingTexture = LoadTexture("assets/graphics/dog/Dog Die.png");
    Texture2D yeetingTexture = LoadTexture("assets/graphics/cat/Dog Die.png");
    int frameCount = 0;
    int direction = 0;
public:
    void walking();
    void update(int frameCount_p) override;
    void animation(int frameCount_p) override;
    void updateState() override;
    WalkingEnemy();
};


#endif //RAYLIBSTARTER_WALKINGENEMY_H

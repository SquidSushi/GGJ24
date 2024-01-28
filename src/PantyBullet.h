//
// Created by jacob on 28.01.2024.
//

#ifndef RAYLIBSTARTER_PANTYBULLET_H
#define RAYLIBSTARTER_PANTYBULLET_H


#include "Entity.h"

class PantyBullet : public Entity {
void updateState() override;
void update(int frameCount_p) override;
void animation(int frameCount_p) override;
};


#endif //RAYLIBSTARTER_PANTYBULLET_H

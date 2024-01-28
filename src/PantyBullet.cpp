//
// Created by jacob on 28.01.2024.
//

#include "PantyBullet.h"

void PantyBullet::updateState() {

}

void PantyBullet::update(int frameCount_p) {
    position.x += velocity.x;
    position.y += velocity.y;
    velocity.y += massGravity;
    wrapAroundScreen();
    if (collisions & 2) {
        toBeDeleted = true;
    }
}

void PantyBullet::animation(int frameCount_p) {
    DrawRectangle(position.x, position.y, 16, 16, PINK);
}

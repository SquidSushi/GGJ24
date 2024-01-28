//
// Created by Oliver on 28.01.2024.
//

#include "Pickup.h"

void Pickup::update(int frameCount_p) {

}

void Pickup::animation(int frameCount_p) {
    DrawRectangle(position.x, position.y, 16, 16, type == 0 ? YELLOW : PINK);
}

//
// Created by jacob on 28.01.2024.
//

#include "BananaTrap.h"
#include "JumpingEnemy.h"
#include "WalkingEnemy.h"

void BananaTrap::getPlaced() {

}

void BananaTrap::commitMurder(Entity *victim) {
    victim->updateState();
}
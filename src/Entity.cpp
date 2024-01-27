//
// Created by jacob on 26.01.2024.
//

#include <cmath>
#include "Entity.h"
#include "enumsAndConstants.h"

void Entity::handleGravity() {
    if((velocity.y + massGravity) < terminalVelocity)
    {
        this->velocity.y += this->massGravity;
        if(this->velocity.y > 0){
            this->state = Falling;
        }
    }
}


void Entity::transformPosition() {
    this->position.x += this->velocity.x;
    this->position.y += this->velocity.y;
}

void Entity::wrapAroundScreen() {
    position.x = fmod(position.x, 16*18);
    if(position.x < 0){
        position.x += 16*18;
    } 
}

void Entity::drawDebug() {

}

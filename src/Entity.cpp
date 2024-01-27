//
// Created by jacob on 26.01.2024.
//

#include <cmath>
#include "Entity.h"
#include "enumsAndConstants.h"

void Entity::handleGravity() {
    if(this->checkForCollision({this->position.x, (this->position.y + this->velocity.y + this->massGravity)}))
    {
        if((velocity.y + massGravity) < terminalVelocity)
        {
            this->velocity.y += this->massGravity;
            if(this->velocity.y < 0){
                this->state = Falling;
            }
        }
    }
}

bool Entity::checkForCollision(Vector2 nextPosition) {
    if(nextPosition.y > 8 * 23 - sourceRec.height){
        this->position.y = 8 * 23 - sourceRec.height;
        this->velocity.y = 0;
        state = Idle;
        return false;
    }
    return true;
}

void Entity::transformPosition() {
    this->position.x += this->velocity.x;
    this->position.y += this->velocity.y;
}

void Entity::wrapAroundScreen() {
    position.x = fmod(position.x, 16*16);
    if(position.x < 0){
        position.x += 16*16;
    } 
}

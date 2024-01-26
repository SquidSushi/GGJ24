//
// Created by jacob on 26.01.2024.
//

#include "Entity.h"

void Entity::handleGravity() {
    if(this->checkForCollision({this->position.x, (this->position.y + velocity.y + this->massGravity)})){
        this->velocity.y += this->massGravity;
    }
}

bool Entity::checkForCollision(Vector2 nextPosition) {
    if(nextPosition.y > 720){
        this->position.y = 720;
        return false;
    }
    return true;
}

void Entity::transformPosition() {
    this->position.x += this->velocity.x;
    this->position.y += this->velocity.y;
}

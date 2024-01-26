//
// Created by jacob on 26.01.2024.
//

#include "Entity.h"
#include "config.h"

void Entity::handleGravity() {
    if(this->checkForCollision({this->position.x, (this->position.y + this->velocity.y + this->massGravity)}))
    {
        if((velocity.y + massGravity) < terminalVelocity)
        {
            this->velocity.y += this->massGravity;
        }
    }
}

bool Entity::checkForCollision(Vector2 nextPosition) {
    if(nextPosition.y > 16*12 - sourceRec.height){
        this->position.y = 16*12 - sourceRec.height;
        this->velocity.y = 0;
        return false;
    }
    return true;
}

void Entity::transformPosition() {
    this->position.x += this->velocity.x;
    this->position.y += this->velocity.y;
}

void Entity::animation(int frameCount_p) {
    DrawTexturePro(entityTexture, sourceRec,{position.x, position.y, 16, 32}, {}, 0, WHITE);
    if(frameCount_p % 6 == 0){
        sourceRec.x += 32;
        if(sourceRec.x == 128){
            sourceRec.x = 8;
        }
    }
}

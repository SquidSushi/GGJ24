//
// Created by jacob on 26.01.2024.
//

#include <cmath>
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

    for (int i = 0; i < 3; i++){
        DrawTexturePro(entityTexture, {currentFrame * 32.0f,0,sourceRec.width + 16, sourceRec.height+16}, {position.x + i * 256 - 256 - 8, position.y, 16+16, 32+16}, {}, 0, WHITE);
    }
    if(frameCount_p % 10 == 0){
       currentFrame++;
    }
}

void Entity::wrapAroundScreen() {
    position.x = fmod(position.x, 16*16);

}

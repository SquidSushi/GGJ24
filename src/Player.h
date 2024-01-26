//
// Created by jacob on 26.01.2024.
//

#ifndef RAYLIBSTARTER_PLAYER_H
#define RAYLIBSTARTER_PLAYER_H
#include "Entity.h"

class Player : public Entity {
public:
    void PlayerMovement();
    bool pressedLeft();
    bool pressedRight();
    bool pressedJump();
    Player(Texture2D _entityTexture, Vector2 _position, Rectangle _sourceRec);
};


#endif //RAYLIBSTARTER_PLAYER_H

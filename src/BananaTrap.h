//
// Created by jacob on 28.01.2024.
//

#ifndef RAYLIBSTARTER_BANANATRAP_H
#define RAYLIBSTARTER_BANANATRAP_H


#include "Entity.h"

class BananaTrap: public Entity {
    void getPlaced();
    void commitMurder(Entity * victim);
};


#endif //RAYLIBSTARTER_BANANATRAP_H
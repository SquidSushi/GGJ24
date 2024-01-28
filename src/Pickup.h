//
// Created by Oliver on 28.01.2024.
//

#ifndef RAYLIBSTARTER_PICKUP_H
#define RAYLIBSTARTER_PICKUP_H


#include "Entity.h"
//this does both be the pickup for panties and bananas
class Pickup : public Entity{
public:
    //inherit from entity
    void updateState() override;
    void animation(int frameCount_p) override;
    void update(int frameCount_p) override;
    void drawDebug() override;
    Pickup(Vector2 _position, Rectangle _sourceRec, int _type);
    int getType();
private:
    int type; //0 for banana, 1 for panty

};


#endif //RAYLIBSTARTER_PICKUP_H

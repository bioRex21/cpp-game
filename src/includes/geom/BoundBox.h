#ifndef BOUNDBOX_H
#define BOUNDBOX_H

#include "Rectangle.h"
#pragma once

class BoundBox
{
public:
    float x0 = 0.0f;
    float y0 = 0.0f;
    float x1 = 0.0f;
    float y1 = 0.0f;
    float width = 0.0f;
    float height = 0.0f;
    float originalWidth = 0.0f;
    float originalHeight = 0.0f;
    bool intersects(BoundBox *collider);
    void update(float newX, float newY, float newScale);
    BoundBox(float x, float y, float width, float height);
    ~BoundBox();

private:

};

#endif

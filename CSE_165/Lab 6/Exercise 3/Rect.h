#ifndef RECT_H
#define RECT_H

#include "Vec.h"

class Rect {
public:
    float x;
    float y;
    float width;
    float height;

    Rect(float x, float y, float width, float height){
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    bool contains(const Vec& point) const {
        return (point.x >= x && point.x <= x + width && point.y <= y && point.y >= y - height);
    }
};

#endif

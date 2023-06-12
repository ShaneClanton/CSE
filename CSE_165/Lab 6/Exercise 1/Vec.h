#ifndef VEC_H
#define VEC_H

#include <iostream>
// check with others
class Vec {
public:
    float x;
    float y;

    Vec(){
        this->x = 0;
        this->y = 0;
    }

    Vec(float x, float y){
        this->x = x;
        this->y = y;
    }

    void set(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void add(const Vec& v) {
        this->x += v.x;
        this->y += v.y;
    }

    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

#endif
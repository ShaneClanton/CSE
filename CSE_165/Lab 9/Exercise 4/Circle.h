#ifndef CIRCLE_H
#define CIRCLE_H

#include "Sortable.h"
#include <iostream>

class Circle : public Sortable {
private:
    float m_radius;

public:
    Circle() : m_radius(0) {}
    Circle(float radius) : m_radius(radius) {}

    float getRadius() const { return m_radius; }

    virtual bool compare(const Sortable* other) {
        const Circle* otherCircle = dynamic_cast<const Circle*>(other);
        if (otherCircle != nullptr) {
            return m_radius > otherCircle->getRadius();
        } else {
            // other is not a Circle, so it must be a Participant
            return false;
        }
    }

    virtual void print() {
        std::cout << "Circle with radius: " << m_radius << std::endl;
    }
};

#endif


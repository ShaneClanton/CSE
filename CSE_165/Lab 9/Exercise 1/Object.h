#ifndef OBJECT_H
#define OBJECT_H

class Object {
public:
    static int count;

    Object() {
        count++;
    }

    Object(const Object&) {
        count++;
    }
};

#endif

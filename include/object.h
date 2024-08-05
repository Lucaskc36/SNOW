#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

class Object {
    public:
    virtual void draw() = 0;
    virtual ~Object() = default;
};
#endif
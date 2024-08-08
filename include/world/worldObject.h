#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <glm/glm.hpp>

class WorldObject {
    public:
    virtual ~WorldObject() = default;
    virtual void update(float deltaTime) = 0;
    virtual void render() const = 0;
    virtual glm::vec3 getPosition() const = 0;
};

#endif

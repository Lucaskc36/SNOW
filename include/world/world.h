#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory>
#include "../rendering/OrthogonalCamera.h"
#include "worldObject.h"

class WorldObject;

class World{
    public:
    World();
    ~World();
    void addObject(const std::shared_ptr<WorldObject>& object);
    void setCamera(const std::shared_ptr<OrthogonalCamera>& camera);
    void update(float deltaTime);
    void render();

    private:

    std::vector<std::shared_ptr<WorldObject>> objects;
    std::shared_ptr<OrthogonalCamera> camera;

};

#endif
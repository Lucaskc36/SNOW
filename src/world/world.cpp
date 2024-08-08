#include "../../include/world/world.h"
#include "../../include/world/worldObject.h"
#include <iostream>

World::World() {}

World::~World() {}

void World::addObject(const std::shared_ptr<WorldObject>& object){
    objects.push_back(object);
}

void World::setCamera(const std::shared_ptr<OrthogonalCamera>& camera){
    this->camera = camera;
}

void World::update(float deltaTime){
    for(const auto& object : objects){
        object->update(deltaTime);
    }

    if(camera){
        //Camera->applyPhysics(delta) //when the camera can move
        if(!objects.empty()){
            camera->setTarget(objects[0]->getPosition());
        }
    }
}

void World::render(){
    for(const auto& object : objects){
        object->render();
    }
    if (camera){
        //render camera's view and any debug info
    }
}
#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

class Camera {
public:
    Camera();
    Camera(const glm::vec3& position, const glm::vec3& target);
    ~Camera(){};

    //Set
    void setPosition(const glm::vec3& position);
    void setTarget(const glm::vec3& target);
    //Get
    virtual glm::mat4 getViewMatrix() const;
    virtual glm::mat4 getProjectionMatrix() const;
    glm::vec3 getPosition() const;
    virtual glm::vec3 getDirection() const;
    glm::vec3 getTarget() const;

protected:
    glm::vec3 target;
    glm::vec3 up;
    glm::vec3 direction;
    glm::vec3 position;
    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;

    //updaters
    virtual void updateViewMatrix() = 0;
    virtual void updateProjectionMatrix() = 0;
};

#endif // CAMERA_H
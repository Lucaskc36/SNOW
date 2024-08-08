#ifndef ORTHOGONALCAMERA_H
#define ORTHOGONALCAMERA_H
#include "camera.h"

class OrthogonalCamera: public Camera{
public:
    OrthogonalCamera();
    OrthogonalCamera(const glm::vec3& position, const glm::vec3 target);

private:
    void updateViewMatrix();
    void updateProjectionMatrix();

    glm::vec3 right;
    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;
};

#endif
#include "../include/rendering/OrthogonalCamera.h"

    OrthogonalCamera::OrthogonalCamera(): Camera(){
        updateViewMatrix();
        updateProjectionMatrix();
    };
    OrthogonalCamera::OrthogonalCamera(const glm::vec3& position, const glm::vec3 target): Camera(position, target){
        updateViewMatrix();
        updateProjectionMatrix();
        };

    void OrthogonalCamera::updateViewMatrix() {
        direction = getDirection();
        right = glm::normalize(glm::cross(direction,glm::vec3(0,1,0)));//direction cross y unit vec
        up = glm::cross(direction, right);
        viewMatrix = glm::lookAt(position, target, up);
    };

    void OrthogonalCamera::updateProjectionMatrix(){
        //ADD Frustrum Variables for zNear & ZFAR
        //param LEFT, RIGHT, BOTTOM, TOP, ZNEAR, ZFAR
       projectionMatrix = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f,100.0f);
    };

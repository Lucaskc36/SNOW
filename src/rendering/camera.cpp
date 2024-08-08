#include "../include/rendering/camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


Camera::Camera():position(glm::vec3(1.0f,1.0f,1.0f)),target(glm::vec3(0.0f,0.0f,0.0f)),up(glm::vec3(0.0f,1.0f,0.0f))
    {};

Camera::Camera(const glm::vec3& position, const glm::vec3& target): position(position),target(target),up(glm::vec3(0.0f,0.0f,1.0f))
    {};

void Camera::setPosition(const glm::vec3& position){
    this->position = position;
};
void Camera::setTarget(const glm::vec3& target){
    this->target = target;
}

glm::vec3 Camera::getDirection() const{
    return glm::normalize(target - position);
};

glm::vec3 Camera::getPosition() const {
    return position;
};

glm::vec3 Camera::getTarget() const {
    return target;
};

glm::mat4 Camera::getViewMatrix() const{
    return viewMatrix;
};
glm::mat4 Camera::getProjectionMatrix() const{
    return projectionMatrix;
}
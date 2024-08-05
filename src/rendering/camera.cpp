#include "../include/rendering/camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
Camera::Camera(){
    //CAMERA SHIT
    position = glm::vec3(0.0f,0.0f,3.0f);
}
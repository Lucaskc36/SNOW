#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

class Camera {
public:
    Camera();
    ~Camera(){};
private:
    glm::vec3 position;
};

#endif // CAMERA_H
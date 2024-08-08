#ifndef COORDINATEAXIS_H
#define COORDINATEAXIS_H

#include "../world/worldObject.h"
#include <GL/gl3w.h>
#include <glm/glm.hpp>

class CoordinateAxis: public WorldObject {
    public:
    CoordinateAxis();
    ~CoordinateAxis();

    void update(float deltaTime) override;
    void render() const override;
    glm::vec3 getPosition() const override;

    private:
    glm::vec3 position;
    GLuint vao, vbo;
    GLuint shaderProgram;

    void setupAxis();
    GLuint compileShader(const char* source, GLenum type);
    GLuint createShaderProgram();
};

#endif
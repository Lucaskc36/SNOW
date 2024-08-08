#include "../../include/objects/coordinateAxis.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
//OPENGL
#include <GL/gl3w.h>

// Simple vertex and fragment shaders for the axis
const char* vertexShaderSource = R"(
#version 330 core
layout(location = 0) in vec3 aPos;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
void main() {
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}
)";

const char* fragmentShaderSource = R"(
#version 330 core
out vec4 FragColor;
uniform vec3 color;
void main() {
    FragColor = vec4(color, 1.0);
}
)";


CoordinateAxis::CoordinateAxis()
        : position(glm::vec3(0.0f, 0.0f, 0.0f)){
        setupAxis();
        shaderProgram = createShaderProgram();    
        }
CoordinateAxis::~CoordinateAxis(){
        glDeleteVertexArrays(1,&vbo);
        glDeleteBuffers(1, &vbo);
        glDeleteProgram(shaderProgram);
        }

        ///@brief Coordinate Axis Shouldn't move ... ever. But, for testing purposes let it.
void CoordinateAxis::update(float deltaTime){
    //position.x += deltaTime * -0.1f;
}

void CoordinateAxis::render() const{
    std::cout << "Rendering axis at pos: ()" << position.x << ", "
                                         << position.y << ", " 
                                         << position.z << std::endl;
    glm::mat4 model = glm::translate(glm::mat4(1.0f),position);
    glm::mat4 view = glm::mat4(1.0f); //use camera's view matrix
    glm::mat4 projection = glm::mat4(1.0f); //Use camera's projection matrix

    GLint modelLoc = glGetUniformLocation(shaderProgram, "model");
    GLint viewLoc = glGetUniformLocation(shaderProgram, "view");
    GLint projectionLoc = glGetUniformLocation(shaderProgram, "projection");

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

    glBindVertexArray(vao);

    // Draw X axis (red)
    glUniform3f(glGetUniformLocation(shaderProgram, "color"), 1.0f, 0.0f, 0.0f);
    glDrawArrays(GL_LINES, 0, 2);

    // Draw Y axis (green)
    glUniform3f(glGetUniformLocation(shaderProgram, "color"), 0.0f, 1.0f, 0.0f);
    glDrawArrays(GL_LINES, 2, 2);

    // Draw Z axis (blue)
    glUniform3f(glGetUniformLocation(shaderProgram, "color"), 0.0f, 0.0f, 1.0f);
    glDrawArrays(GL_LINES, 4, 2);

    glBindVertexArray(0);
    glUseProgram(0);

}
glm::vec3 CoordinateAxis::getPosition() const {
        return position;
}
void CoordinateAxis::setupAxis() {
    float axisVertices[] = {
        // X axis
        0.0f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f,
        // Y axis
        0.0f, 0.0f, 0.0f,  0.0f, 1.0f, 0.0f,
        // Z axis
        0.0f, 0.0f, 0.0f,  0.0f, 0.0f, 1.0f
    };

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(axisVertices), axisVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

GLuint CoordinateAxis::compileShader(const char* source, GLenum type) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    return shader;
}

GLuint CoordinateAxis::createShaderProgram() {
    GLuint vertexShader = compileShader(vertexShaderSource, GL_VERTEX_SHADER);
    GLuint fragmentShader = compileShader(fragmentShaderSource, GL_FRAGMENT_SHADER);

    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        std::cerr << "ERROR::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return program;
}
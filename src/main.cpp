//Third Party
#include <SDL3/SDL.h>
#include <GL/gl3w.h>
    //GL Math
    #include <glm/glm.hpp>
    #include <glm/gtc/matrix_transform.hpp>
    #include <glm/gtc/type_ptr.hpp> 
//StandardLibrary
#include <iostream>
#include <memory>

//ImGUI STUFF
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_opengl3.h"

//CORE
#include "../include/core/engine.h"
//CAMERAS
#include "../include/rendering/OrthogonalCamera.h"
//Objects and World
#include "../include/objects/coordinateAxis.h"
#include "../include/world/world.h"
#include "../include/world/worldObject.h"

//CONTROLLERS
#include "../include/core/controllers.h"


void printOpenGLVersion() {
    const GLubyte* renderer = glGetString(GL_RENDERER); // Get renderer string
    const GLubyte* version = glGetString(GL_VERSION);   // Version as a string
    GLint major, minor;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);

    std::cout << "Renderer: " << renderer << std::endl;
    std::cout << "OpenGL version supported: " << version << std::endl;
    std::cout << "OpenGL version (integer): " << major << "." << minor << std::endl;
}


int main(){
    //printOpenGLVersion();
    std::unique_ptr<Engine> engine = std::make_unique<Engine>();

    engine->initialize();
    //initializing the orthogonal Camera
    glm::vec3 cameraPos(0.0f,0.0f,5.0f);
    glm::vec3 targetPos(0.0f,0.0f,0.0f);
    OrthogonalCamera orthoCamera(cameraPos, targetPos);
     // Create the world and add the coordinate axis object
    
    std::shared_ptr<World> world = std::make_shared<World>();
    std::shared_ptr<CoordinateAxis> axisObject = std::make_shared<CoordinateAxis>();
    world->addObject(axisObject);

    // Set the camera for the world
    std::shared_ptr<OrthogonalCamera> camera;
    world->setCamera(camera);

    engine->run();
    engine->initialize();
};
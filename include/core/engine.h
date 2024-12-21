/*
KOREY LUCAS
CREATED 1/27/24

ENGINE.H

HANDLES



*/
#ifndef ENGINE_H
#define ENGINE_H

#include <SDL3/SDL.h>
#include <GL/gl3w.h>
#include <string>
#include <memory>
#include "ui.h"
#include "controller.h"
#include "integrator.h"
#include "../rendering/OrthogonalCamera.h"
#include "../managers/UIManager.h"

class Engine {
public:
    Engine();
    Engine(const std::string &windowName,
                unsigned int windowHeight,
                unsigned int windowWidth);
    ~Engine();
    bool initialize();
    void run();
    void shutdown();
    void printOpenGLVersion();
    

private:
    void handleEvents();
    void update();
    void render();

    SDL_Window* window_;
    SDL_GLContext glContext_;
    bool isRunning_;
    int screenWidth_;
    int screenHeight_;
    std::string windowName_;

    UIManager uiManager;
    std::shared_ptr<Controller> controller;
    std::shared_ptr<Integrator> integrator = std::make_shared<Integrator>();
};

#endif // ENGINE_H
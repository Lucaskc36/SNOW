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
#include "ui.h"
#include <string>
#include <memory>
#include "../rendering/camera.h"

class Engine {
public:
    Engine();
    Engine(std::string &windowName,
                unsigned int windowHeight,
                unsigned int windowWidth);
    ~Engine();
    bool initialize();
    void run();
    void shutdown();

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

    std::unique_ptr<UI> ui;
    std::unique_ptr<Camera> camera;
};

#endif // ENGINE_H
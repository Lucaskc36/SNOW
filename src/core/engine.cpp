#include  "../include/core/engine.h"
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_opengl3.h"
#include <iostream>

Engine::Engine():
                glContext_(nullptr),
                window_(nullptr),
                windowName_("SNOW DEFAULT"),
                screenWidth_(1440),
                screenHeight_(800),
                ui(std::make_unique<UI>()),
                camera(std::make_unique<Camera>())
                {};

Engine::Engine(std::string& windowName,
    unsigned int windowHeight,
    unsigned int windowWidth):

            glContext_(nullptr),
            window_(nullptr),
            windowName_(windowName),
            screenWidth_(windowHeight),
            screenHeight_(windowWidth),
            ui(std::make_unique<UI>()),
            camera(std::make_unique<Camera>())

            {};

Engine::~Engine(){
    shutdown();
}



bool Engine::initialize(){

    //Initialization check for audio and video, 
    //This might not be right since we haven't exctly initiated anything yet. 
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
        SDL_Log("SDL could not be INITIALIZED %s\n", SDL_GetError());
        return false;
    }

    //should use SDL_GL_GetAttribute() to check the values after creating the OpenGL context, 
    //since the values obtained can differ from the requested ones.
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    
    window_ = SDL_CreateWindow(windowName_.c_str(),
        screenWidth_, screenHeight_,
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    if(window_ == nullptr){
        SDL_Log("SDL could not be INITIALIZED %s\n", SDL_GetError());
        isRunning_ = false;
        return false;
    }
    glContext_ = SDL_GL_CreateContext(window_);
    if (!glContext_) {
        return false;
    }
    if (gl3wInit() != GL3W_OK){
        std::cerr << "Failed to initialize GL3W" << std::endl;
    }
    SDL_GL_SetSwapInterval(1); //enable vsync
    // Set OpenGL viewport and other settings
    glViewport(0, 0, screenWidth_, screenHeight_);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    // Initialize UI
    if (!ui->initialize(window_, glContext_)) {
        std::cerr << "Failed to initialize UI" << std::endl;
        return false;
    }

    isRunning_ = true;
    return true;
}
void Engine::run() {

    while (isRunning_) {
        handleEvents();
        update();
        render();
        SDL_GL_SwapWindow(window_);
    }

}

void Engine::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Render ImGui UI
    ui->render(*camera);

    // Render other objects, UI, etc.
}
void Engine::handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0){
        if(event.type == SDL_EVENT_QUIT){
            isRunning_ = false;
        }
        ImGui_ImplSDL3_ProcessEvent(&event);
    }
}
void Engine::update() {
    // Update game state, physics, objects.
}
void Engine::shutdown() {
    ui->shutdown();
    SDL_GL_DestroyContext(glContext_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
}
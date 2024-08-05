/*
UI.h
KOREY LUCAS

UI

IMPLIMENTS IMGUI handles a renderer object to
be applied to constructor


*/
#ifndef UI_H
#define UI_H

#include <SDL3/SDL.h>
#include "../rendering/camera.h"

class UI {
public:
    UI();
    ~UI();
    
    bool initialize(SDL_Window* window, SDL_GLContext glContext);
    void render(Camera& camera);
    void shutdown();
    
private:
    // ImGui context or any other GUI library context
};

#endif // UI_H
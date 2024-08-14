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
    
    virtual void UI_render();
    virtual void shutdown();
    
private:
    bool _enabled;
    virtual void CreateGuiElements();
    // ImGui context or any other GUI library context
};

#endif // UI_H
/*
UI.h
KOREY LUCAS

UI

IMPLIMENTS IMGUI handles a renderer object to
be applied to constructor


*/

#pragma once
#ifndef UI_H
#define UI_H

#include "Engine.h"
#include <SDL2/SDL.h>

#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>

class Engine;

class UI{
    public:
    UI(Engine* engine, int* x, int *y):engine_(engine),x_(x),y_(y){};
    ~UI();
    void init();
    void inputHandling(SDL_Event* e);
    void render();

    inline void renderDrawData(){ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());}

    protected:
    Engine* engine_;
    int* x_,* y_;

};

#endif
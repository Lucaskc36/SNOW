#include <SDL3/SDL.h>
#include <iostream>
#include <GL/gl3w.h>
#include <iostream>
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_opengl3.h"
#include "../include/core/engine.h"

int main(){
    std::cout << "Hello Word" << std::endl;
    Engine engine;
    engine.initialize();
    engine.run();
    engine.shutdown();
};
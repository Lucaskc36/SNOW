#include "../../include/managers/UIManager.h"
//ImGUI STUFF
#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_opengl3.h>

UIManager::UIManager(){

}
UIManager::~UIManager(){

};

bool UIManager::Init(SDL_Window* window, SDL_GLContext glContext){
    
    // Initialize ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

// Setup ImGui binding
    if (!ImGui_ImplSDL3_InitForOpenGL(window, glContext)) {
        return false;
    }
    if (!ImGui_ImplOpenGL3_Init("#version 330")) {
        return false;
    }

    // Setup style
    ImGui::StyleColorsDark();
    
    return true;
}
void UIManager::addUI(std::shared_ptr<UI> element){
    elements.push_back(element);
}
void UIManager::removeElement(std::shared_ptr<UI> element){
    return;
}
void UIManager::render(){
    for(auto& element: elements){
        element->UI_render();
    }
}
void UIManager::shutdown(){
    for(auto& element: elements){
        element->shutdown();
    }
}
#include "../include/core/ui.h"
#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_opengl3.h>

UI::UI() {
    // Constructor logic
}

UI::~UI() {
    shutdown();
}


void UI::UI_render() {
    // Start the ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();
    
    //Create GUI Elements;
    CreateGuiElements();

    // Render GUI
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UI::shutdown() {
    // Cleanup ImGui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();
}
void UI::CreateGuiElements(){
    ImGui::Begin("DEFAULT");
    ImGui::Text("Frustum: ..."); // Display camera frustum information
    ImGui::End();
}
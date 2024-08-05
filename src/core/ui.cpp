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

bool UI::initialize(SDL_Window* window, SDL_GLContext glContext) {
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

void UI::render(Camera& camera) {
    // Start the ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();
    
    // Create GUI elements
    ImGui::Begin("Camera Info");
    ImGui::Text("Frustum: ..."); // Display camera frustum information
    ImGui::End();

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
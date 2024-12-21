#include "../../include/core/integrator.h"
#include "../../external/runge-kutta/runge-kutta.h"
#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_opengl3.h>
#include <string>
#include <iostream>
Integrator::Integrator(){

}

void Integrator::CreateGuiElements(){

    static double y_0 = 0.0;
    static double t_0 = 0.0;
    static double dt = 0.1;
    static int steps = 1;
    auto myFunction = [](double t, double y) { return -2 * y; };    //Begins the Integrator struture
    
    ImGui::Begin("Runge-kutta Integrator", NULL);
    
        ImGui::InputDouble("Initial Condition (y_0)", &y_0);
        ImGui::InputDouble("Initial time (t_0)", &t_0);
        ImGui::InputDouble("Step Size (dt)", &dt);
        ImGui::InputInt("steps", &steps);


        if(ImGui::Button("Integrate")){
            result = integrate(myFunction,t_0, y_0, steps, dt);
        }
        //Print Text
        ImGui::Text("Results:");
        for (size_t i = 0; i < result.size(); ++i) {
            ImGui::Text("[%zu]: %.5f", i, result[i]);
        }
    ImGui::End();
}
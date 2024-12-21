#ifndef INTEGRATOR_H
#define INTEGRATOR_H
#include "ui.h"
#include <SDL3/SDL_gamepad.h>
#include <SDL3/SDL.h>

class Integrator: public UI{
    public:
    Integrator();

    private:
    void CreateGuiElements() override;
    std::vector<double> result;


};

#endif
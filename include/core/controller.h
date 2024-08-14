#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "ui.h"
#include <SDL3/SDL_gamepad.h>
#include <SDL3/SDL.h>

class Controller: public UI{
    public:
    Controller();
    ~Controller();
    Uint16 GetGamepadFirmwareVersion();//returns the version
    Uint16 GetJoystickPowerInfo();
    void initController();//another ugly function to be refactored into init
    void vibrate(int duration = 1000);

    private:
    void CreateGuiElements() override;
    SDL_Gamepad *_gamepad;
    void findGamepad();


};

#endif
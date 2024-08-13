#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <SDL3/SDL_gamepad.h>

class Controller{
    public:
    Controller();
    Uint16 GetGamepadFirmwareVersion();//returns the version
    Uint16 GetJoystickPowerInfo();

    private:
    SDL_Gamepad *gamepad;

};

#endif
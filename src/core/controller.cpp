#include "../../include/core/controller.h"
#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_opengl3.h>
#include <string>
#include <iostream>

Controller::Controller():UI(){
}
Controller::~Controller(){
    SDL_CloseGamepad(_gamepad);
}
void Controller::CreateGuiElements(){
    std::string ControllerID = "Controller ID: " + std::to_string(SDL_GetGamepadID(_gamepad));
    ImGui::Begin(ControllerID.c_str());
    if(ImGui::Button("VibrateController")){
        vibrate();
    }
    if(ImGui::Button("Vibrate Controller Low Freq")){
        SDL_RumbleGamepad(_gamepad, 0xFFFF, 0x0000, 1000);
    }
    if(ImGui::Button("Vibrate Controller High Freq")){
        SDL_RumbleGamepad(_gamepad, 0x0000, 0xFFFF, 1000);
    };
    ImGui::Text(ControllerID.c_str());
    ImGui::End();
}
void Controller::initController(){
    findGamepad();
}

Uint16 Controller::GetGamepadFirmwareVersion(){
    return 0;
}
Uint16 Controller::GetJoystickPowerInfo(){
    return 0;
}
//Really ugly code on finding the controller and testing.
void Controller::findGamepad(){
    // INITIALIZE CONTROLLERS
if (SDL_HasGamepad() == SDL_TRUE) {
    int gamePadCount = 0;
    std::cout << "GAMEPAD DETECTED" << std::endl;

    // Get the array of joystick IDs
    SDL_JoystickID* gamePadIDs = SDL_GetGamepads(&gamePadCount);

    if (gamePadIDs) {
        std::cout << "GAMEPAD COUNT: " << gamePadCount << std::endl;

        // Iterate through all detected gamepads
        for (int i = 0; i < gamePadCount; i++) {
            SDL_JoystickID joystickID = gamePadIDs[i];
            std::cout << "Joystick ID: " << joystickID << std::endl;

            // Check if the joystick ID is a valid gamepad
            if (SDL_IsGamepad(joystickID)) {
                // Get the gamepad from the joystick ID
                std::cout << "Getting Gamepad from ID" << std::endl;

                SDL_Gamepad* openedGamepad = SDL_OpenGamepad(joystickID);
                _gamepad = SDL_GetGamepadFromID(joystickID);
                if (_gamepad) {
                    std::cout << "Opening GamePad: " << _gamepad << std::endl;

                    // Open the gamepad for use
                    if (openedGamepad) {
                        std::cout << "Returned Memory Address: " << openedGamepad << std::endl;

                        // Test rumble functionality
                        std::cout << "Testing Rumble" << std::endl;
                        std::cout << "3" << std::endl;
                        SDL_Delay(1000);
                        std::cout << "2" << std::endl;
                        SDL_Delay(1000);
                        std::cout << "1" << std::endl;
                        SDL_Delay(1000);
                        std::cout << "1000 ms Rumble" << std::endl;

                        int response = SDL_RumbleGamepad(openedGamepad, 0xFFFF, 0xFFFF, 1000);
                        std::cout << "Test Finished, Return value: " << response << std::endl;

                        // Remember to close the gamepad when done
                        
                    } else {
                        std::cerr << "Failed to open gamepad with ID: " << joystickID << std::endl;
                        std::cerr << "ERROR: " << SDL_GetError() << std::endl;
                    }
                } else {
                    std::cerr << "Failed to get gamepad from ID: " << joystickID << std::endl;
                    std::cerr << "ERROR: " << SDL_GetError() << std::endl;
                }
            } else {
                std::cerr << "Joystick ID: " << joystickID << " is not a valid gamepad." << std::endl;
            }
        }
    } else {
        std::cerr << "Failed to get gamepad IDs." << std::endl;
    }
} else {
    std::cout << "No game controller" << std::endl;
    }
}
///
void Controller::vibrate(int duration_ms){
    SDL_RumbleGamepad(_gamepad, 0xFFFF, 0xFFFF, duration_ms);
}
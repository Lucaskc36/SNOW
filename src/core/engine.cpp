#include  "../include/core/engine.h"
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_opengl3.h"
#include <iostream>

Engine::Engine():
                glContext_(nullptr),
                window_(nullptr),
                windowName_("SNOW DEFAULT"),
                screenWidth_(1440),
                screenHeight_(800),
                ui(std::make_unique<UI>()),
                camera(std::make_unique<OrthogonalCamera>())
                {};

Engine::Engine(const std::string& windowName,
    unsigned int windowHeight,
    unsigned int windowWidth):

            glContext_(nullptr),
            window_(nullptr),
            windowName_(windowName),
            screenWidth_(windowHeight),
            screenHeight_(windowWidth),
            ui(std::make_unique<UI>()),
            camera(std::make_unique<OrthogonalCamera>())

            {
                std::cout << "HELPP" << std::endl;

            };

Engine::~Engine(){
    shutdown();
}



bool Engine::initialize() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMEPAD) != 0) {
        SDL_Log("SDL could not be initialized: %s\n", SDL_GetError());
        return false;
    }

    // Set OpenGL attributes
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // Create an SDL window with an OpenGL context
    window_ = SDL_CreateWindow(windowName_.c_str(), screenWidth_, screenHeight_, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    if (!window_) {
        SDL_Log("Window could not be created: %s\n", SDL_GetError());
        return false;
    }

    glContext_ = SDL_GL_CreateContext(window_);
    if (!glContext_) {
        SDL_Log("OpenGL context could not be created: %s\n", SDL_GetError());
        return false;
    }

    // Enable vsync
    if (SDL_GL_SetSwapInterval(1) < 0) {
        SDL_Log("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
    }

    // Initialize gl3w
    if (gl3wInit() != 0) {
        std::cerr << "Failed to initialize OpenGL loader!" << std::endl;
        return false;
    }

    // Check if the required OpenGL version is supported
    if (!gl3wIsSupported(3, 3)) {
        std::cerr << "OpenGL 3.3 not supported!" << std::endl;
        return false;
    }

    // Print OpenGL version
    printOpenGLVersion();

    // Set OpenGL viewport and other settings
    glViewport(0, 0, screenWidth_, screenHeight_);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    if (!ui->initialize(window_, glContext_)) {
        std::cerr << "Failed to initialize UI" << std::endl;
        return false;
    }
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
                SDL_Gamepad* gamepad = SDL_GetGamepadFromID(joystickID);
                if (gamepad) {
                    std::cout << "Opening GamePad: " << gamepad << std::endl;

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
                        SDL_CloseGamepad(openedGamepad);
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

    isRunning_ = true;
    return true;
}
void Engine::printOpenGLVersion() {
    const GLubyte* renderer = glGetString(GL_RENDERER);
    const GLubyte* version = glGetString(GL_VERSION);
    GLint major, minor;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);

    std::cout << "Renderer: " << renderer << std::endl;
    std::cout << "OpenGL version supported: " << version << std::endl;
    std::cout << "OpenGL version (integer): " << major << "." << minor << std::endl;
}

void Engine::run() {

    while (isRunning_) {
        handleEvents();
        update();
        render();
        SDL_GL_SwapWindow(window_);
    }

}

void Engine::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Render ImGui UI
    ui->render();

    // Render other objects, UI, etc.
}
void Engine::handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0){
        if(event.type == SDL_EVENT_QUIT){
            isRunning_ = false;
        }
        ImGui_ImplSDL3_ProcessEvent(&event);
    }
}
void Engine::update() {
    // Update game state, physics, objects.
}
void Engine::shutdown() {
    ui->shutdown();
    SDL_GL_DestroyContext(glContext_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
}
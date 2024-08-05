/*
KOREY LUCAS
CREATED 1/27/24

ENGINE.H

HANDLES


NOTE:
THE FPS IS ONLY BEING REGULATE BY DELAYING by 16.67 MILLISECONDS


*/

#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include "UI.h"
class UI;
class Engine{
    public:
        Engine();
        Engine(const char* windowName,
         const unsigned int windowHeight,
          const unsigned int windowWidth);
        ~Engine();

        bool initialize();
        void render();
        void renderObjects();
        void handleEvents(UI* overlay);
        inline void stopRunning(){running_ = false;}
        inline bool isRunning() const {return running_;}

        inline SDL_Renderer* getRenderer() const {return renderer_;}
        inline SDL_Window* getWindow()const{return window_;}
        inline unsigned int getWindowWidth() const {return windowWidth_;}
        inline unsigned int getWindowHeight() const {return windowHeight_;}
        inline float getDeltaTime() {return *deltaTime;}//returns in seconds

        void close();

    protected:
        bool running_;
        SDL_Renderer* renderer_;
        SDL_Window* window_;
        const char* windowName_;
        const unsigned int windowWidth_;
        const unsigned int windowHeight_;
        SDL_Event e_;
        Uint32 prevTime;//in seconds
        Uint32 currentTime;//in seconds
        float* deltaTime;//CONVERTED TO MILLISECONDS


};

#endif
#pragma once
#include <SDL2/SDL.h>
#include "../include/Engine.h"
#include <SDL2_image/SDL_image.h>
class Ball{
    public: 
        Ball(Engine* engine, int x, int y, int rad);
        ~Ball();
        //void poll_events(SDL_Event &event);
        void render(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        void update();

        inline int get_x() const {return x_;}
        inline int get_y() const {return y_;}
        inline int* x_speed_ptr() {return &x_speed;}
        inline int* y_speed_ptr() {return &y_speed;}
    private:
        Engine* engine;
        SDL_Renderer* renderer_;
        SDL_Surface* surface_;
        float x_, y_;
        int radius_, x_speed, y_speed, winWidth, winHeight;
        SDL_Texture* texture;
        SDL_Rect* srcrect;
        SDL_Rect* dstrect;
};
#include <SDL.h>
#include "Clock.h"
#include <iostream>

Clock::Clock() {
    deltaT = 1.2;

    lastTime = SDL_GetTicks();
    characterLifeTime = 0;
    
    pause = true;
    start = false;
    animationRunning = false;
}

void Clock::reset() {
    lastTime = SDL_GetTicks();
}

void Clock::tick() {

    lastTime = SDL_GetTicks();
}

void Clock::delay() {
    int frameTime = SDL_GetTicks() - lastTime;
    if (frameDelay > frameTime)
    {
        SDL_Delay(frameDelay - frameTime);
    }
}

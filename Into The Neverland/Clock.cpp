#include <SDL.h>
#include "Clock.h"
#include <iostream>

Clock::Clock() {
    lastTime = SDL_GetTicks();
    pause = true;
    start = false;
}

void Clock::reset() {
    lastTime = SDL_GetTicks();
}

void Clock::tick() {

    double currentTime = SDL_GetTicks();
    //std::cout << "[Clocks] curentTime:" << currentTime << std::endl;

    timeBetweenFrames = (currentTime - lastTime) / 1000.0f;
    lastTime = currentTime;

    //std::cout << "[Clocks] timeBetweenFrames:" << timeBetweenFrames << std::endl;
}

double Clock::getTimeBetweenFrames() {
    return timeBetweenFrames;
}
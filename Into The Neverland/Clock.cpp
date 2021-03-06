#include <SDL.h>
#include "Clock.h"

Clock::Clock() {
    lastTime = SDL_GetTicks();
}

void Clock::reset() {
    lastTime = SDL_GetTicks();
}

void Clock::tick() {

    double currentTime = SDL_GetTicks();
    timeBetweenFrames = (currentTime - lastTime) / 1000.0f;
    lastTime = currentTime;

}

double Clock::getTimeBetweenFrames() {
    return timeBetweenFrames;
}
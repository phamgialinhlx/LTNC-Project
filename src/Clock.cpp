#include <SDL2/SDL.h>
#include <iostream>
#include "Clock.h"
#include "Log.h"

Clock::Clock()
{
    gameState = OPENING_STATE;
    deltaT = 1.2;

    lastTime = SDL_GetTicks();
    characterLifeTime = 0;

    pause = true;
    restart = false;
    quit = false;

    Log::log("[Clock] init succesfully");
}

void Clock::reset()
{
    lastTime = SDL_GetTicks();
}

void Clock::tick()
{

    lastTime = SDL_GetTicks();
}

void Clock::delay()
{
    int frameTime = SDL_GetTicks() - lastTime;
    //std::cout << "FPS: " << 1000 / frameTime << std::endl;
    if (frameDelay > frameTime)
    {
        SDL_Delay(frameDelay - frameTime);
    }
}

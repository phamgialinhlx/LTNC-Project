#include "Inputs.h"
#include "Log.h"
#include <iostream>

Inputs::Inputs() {
    isClicked = false;
    quit = false;

	Log::log("[Inputs] init succesfully");

}

bool Inputs::getQuit() {
    return quit;
}

bool Inputs::isKeyDown(int key) {
    return keyStates[key];
}

bool Inputs::checkForQuit(SDL_Event event) {
    if (event.type == SDL_QUIT) {
        return true;
    }
    return false;

}


void Inputs::update() {
    isClicked = false;
    keyStates = SDL_GetKeyboardState(NULL);

    while (SDL_PollEvent(&event)) {
        
        if (checkForQuit(event)) {
            quit = true;
        }

        if (event.type == SDL_MOUSEBUTTONUP) {
            isClicked = true;
        }

        if (event.type == SDL_MOUSEMOTION) {
            mouseX = event.motion.x;
            mouseY = event.motion.y;
        } 
    }
}

bool Inputs::click() {
    return isClicked;
}




int Inputs::getMouseX() {
    return mouseX;
}

int Inputs::getMouseY() {
    return mouseY;
}
#include "Inputs.h"
#include <iostream>

Inputs::Inputs() {
    isClicked = false;
    quit = false;
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

    keyStates = SDL_GetKeyboardState(NULL);

    SDL_Event event;
    while (SDL_PollEvent(&event)) {

        if (checkForQuit(event)) {
            quit = true;
        }

        if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
            switch (event.type) {
            case SDL_MOUSEMOTION:
                mouseX = event.motion.x;
                mouseY = event.motion.y;
                break;
            case SDL_MOUSEBUTTONDOWN:
                isClicked = true;
                break;

            case SDL_MOUSEBUTTONUP:
                isClicked = false;
                break;
            }
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
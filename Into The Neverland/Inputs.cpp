#include "Inputs.h"

Inputs::Inputs() {
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
    while (SDL_PollEvent(&event) != 0) {

        if (checkForQuit(event)) {
            quit = true;
        }

        if (event.type == SDL_MOUSEMOTION) {
            mouseX = event.motion.x;
            mouseY = event.motion.y;
        }

    }
}

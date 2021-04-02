#include "Graphics.h"


bool Graphics::initSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
        printf("Error: Failed to init SDL2: %s\n", SDL_GetError());
        return false;
    }


    screenWindow = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    if (screenWindow == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return false;
    }
    renderer = SDL_CreateRenderer(screenWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        printf("Could not init renderer: %s\n", SDL_GetError());
        return false;
    }
    return true;
}

Graphics::Graphics()
{
    initSDL();
    resources = new Resources(renderer);
    resources->loadResources();
    
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(screenWindow);
    SDL_DestroyRenderer(renderer);
    delete resources;
    resources = NULL;

}

void Graphics::renderGameObjects(std::vector<GameObjects*>* gameObjects, Clock *clock) {
    

    int buttonID = -1;
    for (int i = 0; i < gameObjects->size(); i++) {
        if ((*gameObjects)[i]->getID() == 4) {
            buttonID = i;
        }
        else if (!clock->start){
            if ((*gameObjects)[i]->getID() == 0) {
                (*gameObjects)[i]->render(renderer, resources, clock);
            }
        }
        else {
            (*gameObjects)[i]->render(renderer, resources, clock);
        }
    }
    (*gameObjects)[buttonID]->render(renderer, resources, clock);
}

void Graphics::clearScreen() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Graphics::rendererPresent() {

    SDL_RenderPresent(renderer);

}

int Graphics::getScreenWidth() {
    return screenWidth;
}
int Graphics::getScreenHeight() {
    return screenHeight;
}


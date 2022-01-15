#include "Graphics.h"
#include "Effects.h"

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
	Log::log("[Graphics] init succesfully");
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(screenWindow);
    SDL_DestroyRenderer(renderer);
    delete resources;
    resources = NULL;

}

void Graphics::renderGameObjects(std::vector<GameObjects*>* gameObjects, Clock *clock, Effects *effects) {
    clearScreen();
    switch (effects->effectType)
    {
    case NONE:
        for (int i = 0; i < gameObjects->size(); i++) {
            (*gameObjects)[i]->render(renderer, resources, clock);
        }
        break;

    case CREDIT:
        effects->render(renderer, resources, clock);
        break;

    case FADE:
    case FLASH:
        for (int i = 0; i < gameObjects->size(); i++) {
            (*gameObjects)[i]->render(renderer, resources, clock);
        }
        effects->render(renderer, resources, clock);
        break;
    }
    rendererPresent();
}

void Graphics::clearScreen() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Graphics::rendererPresent() {

    SDL_RenderPresent(renderer);

}




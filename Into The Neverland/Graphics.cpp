#include "Graphics.h"

const int Graphics::screenWidth = 900, Graphics::screenHeight = 400;
const std::string Graphics::windowTitle = "Into The Neverland: 9 + 1 = 11";


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
}

void Graphics::renderGameObjects(std::vector<GameObjects*>* gameObjects, Clock *clock) {
    

    int temp = -1;
    for (int i = 0; i < gameObjects->size(); i++) {
        if ((*gameObjects)[i]->getID() != 4) {
            (*gameObjects)[i]->render(renderer, resources, clock);
        }
        else {
            temp = i;
        }
    }
    (*gameObjects)[temp]->render(renderer, resources, clock);


    if (!clock->start) {
        renderTransparentBlackBG();
    }
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

void Graphics::renderTransparentBlackBG() {
    SDL_Texture* texture;
    texture = resources->getTexture("black", 0);


    SDL_Rect dst = { 0, 0, 900, 400 };

    SDL_SetTextureAlphaMod(texture, 60);

    SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0,
        NULL, SDL_FLIP_NONE);
}


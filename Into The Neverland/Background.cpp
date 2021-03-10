#include "Background.h"


backGround::backGround(double vX, double vY, double x, double y, double width, double height, std::vector<GameObjects*>* gameObjects)
                      :GameObjects(x, y, width, height) {
    this->vX = vX;
    this->vY = vY;
    
    this->x = x;
    this->y = y;


    this->width = width;
    this->height = height;
    this->gameObjects = gameObjects;
}


void backGround::render(SDL_Renderer* renderer, Resources* resources, double timeBetweenFrames) {
    SDL_Texture* texture;
    texture = resources->getTexture("background");

    SDL_Rect dst = {
        x,
        y,  
        width,
        height
    };
    SDL_Rect dst2 = {
        x + width,
        y,
        width,
        height
    };
    SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0,
        NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(renderer, texture, NULL, &dst2, 0,
        NULL, SDL_FLIP_NONE);
    
}

void backGround::update(double timeBetweenFrames, Inputs *inputs) {
    x -= vX*timeBetweenFrames;
    if (x < -width)
    {
        x = 0;
    }
}

int backGround::getWidth() {
    return width;
}

int backGround::getHeight() {
    return height;
}
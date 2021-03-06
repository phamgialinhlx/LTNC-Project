#include "Background.h"


backGround::backGround(int vX, int vY, int x, int y, int width, int height, std::vector<GameObjects*>* gameObjects)
                      :GameObjects(x, y, width, height) {
    this->vX = vX;
    this->vY = vY;
    
    this->x = x;
    this->y = y;

    scrollingOffset = 0;

    this->width = width;
    this->height = height;
    this->gameObjects = gameObjects;
}


void backGround::render(SDL_Renderer* renderer, Resources* resources, double timeBetweenFrames) {
    SDL_Texture* texture;
    texture = resources->getTexture("background");


    int textureWidth, textureHeight;
    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
    SDL_Rect dst = {
        scrollingOffset,
        y,
        width,
        height
    };
    SDL_Rect dst2 = {
        scrollingOffset + width,
        y,
        width,
        height
    };
    SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0,
        NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(renderer, texture, NULL, &dst2, 0,
        NULL, SDL_FLIP_NONE);
    
}

void backGround::update(double timeBetweenFrames) {
    --scrollingOffset;
    if (scrollingOffset < -width)
    {
        scrollingOffset = 0;
    }
}

int backGround::getWidth() {
    return width;
}

int backGround::getHeight() {
    return height;
}
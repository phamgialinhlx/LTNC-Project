#include "Background.h"

backGround::backGround(int width, int height, std::vector<GameObjects*>* gameObjects)
                      :GameObjects(x, y, width, height) {
    this->width = width;
    this->height = height;
    this->gameObjects = gameObjects;
}


void backGround::render(SDL_Renderer* renderer, Resources* resources) {
    SDL_Texture* texture;
    texture = resources->getTexture("background");

    int texture_width, texture_height;
    SDL_QueryTexture(texture, NULL, NULL, &texture_width, &texture_height);
    SDL_Rect dst = {
        (int)x,
        (int)y,
        texture_width,
        texture_height
    };

    SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0,
        NULL, SDL_FLIP_NONE);
}
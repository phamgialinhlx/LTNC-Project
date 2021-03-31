#include "Background.h"


backGround::backGround(double vX, double vY, double x, double y, double width, double height, std::vector<GameObjects*>* gameObjects)
                      :GameObjects(x, y, width, height, width, height) {
    //std::cout << x << "_" << std::endl;
    this->vX = vX;
    this->vY = vY;
    this->gameObjects = gameObjects;
}


void backGround::render(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
    //std::cout << x << "_" << std::endl;
    SDL_Texture* texture;
    texture = resources->getTexture("background", 0);
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

void backGround::update(Clock* clock, Inputs *inputs) {
    x -= vX * clock->getTimeBetweenFrames();
    if (x < -width)
    {
        x = 0;
    }
}


bool backGround::isAlive() {
    return true;
}

int backGround::getID() {
    return 0;
}

void backGround::die() {

}
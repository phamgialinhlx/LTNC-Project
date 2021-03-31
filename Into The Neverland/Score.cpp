#include "Score.h"


Score::Score(int x, int y, std::vector<GameObjects*>* gameObjects) :GameObjects(x, y, width, height, screenWidth, screenHeight)
{
    this->gameObjects = gameObjects;
}

void Score::render(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
    SDL_Texture* texture;

    std::string score = std::to_string(std::lround(characterLifeTime));

    texture = resources->createTextTexture(score);


    int textWidth, textHeight;
    SDL_QueryTexture(texture, NULL, NULL, &textWidth, &textHeight);

    SDL_Rect dst = {
        x,
        y,
        textWidth,
        textHeight
    };

    SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0,
        NULL, SDL_FLIP_NONE);
    SDL_DestroyTexture(texture);
}

void Score::update(Clock* clock, Inputs* inputs) {
    if (!clock->pause) {
        characterLifeTime += clock->getTimeBetweenFrames() * 5;
        //std::cout << "[Text] characterLifeTime:" << characterLifeTime << std::endl;
    }

}


bool Score::isAlive() {
    return true;
}
int Score::getID() {
    return 3;
}
void Score::die() {

}

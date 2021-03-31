#include "Text.h"


Text::Text(int x, int y, std::vector<GameObjects*>* gameObjects):GameObjects(x, y, width, height, screenWidth, screenHeight)
{
    this->gameObjects = gameObjects;
}

void Text::render(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
    renderScore(renderer, resources, clock);
    //renderNote(renderer, resources, clock);
}

void Text::update(Clock* clock, Inputs* inputs) {
    if (!clock->pause) {
        characterLifeTime += clock->getTimeBetweenFrames() * 5;
        //std::cout << "[Text] characterLifeTime:" << characterLifeTime << std::endl;
    }

}


void Text::renderScore(SDL_Renderer* renderer, Resources* resources, Clock* clock) {

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

bool Text::isAlive() {
    return true;
}
int Text::getID() {
    return 3;
}
void Text::die() {

}

void Text::renderNote(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
    SDL_Texture* texture = NULL;

    std::string text = "PRESS SPACE TO START THE GAME";

    texture = resources->createTextTexture(text);

    int textWidth, textHeight;
    SDL_QueryTexture(texture, NULL, NULL, &textWidth, &textHeight);

    SDL_Rect dst = {
        300,
        350,
        textWidth,
        textHeight
    };

    SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0,
        NULL, SDL_FLIP_NONE);
    SDL_DestroyTexture(texture);
}


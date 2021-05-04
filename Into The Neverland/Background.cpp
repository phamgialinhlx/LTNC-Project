#include "Background.h"

enum mushroom
{
    SMALL_MUSHROOM,
    BIG_MUSHROOM
};

backGround::backGround(double x, double y, double width, double height, std::vector<GameObjects*>* gameObjects)
                      :GameObjects(x, y, width, height, width, height, hitbox) {
    //std::cout << x << "_" << std::endl;
    this->gameObjects = gameObjects;
    hasMushroom = false;
    typeOfMushroom = -1;
}


void backGround::render(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
    switch (clock->gameState) {
    case OPENING_STATE:
    case START_STATE:
    case GAME_OVER_STATE:
        break;
    case PAUSE_STATE:
    {
        //std::cout << "[Background] render" << std::endl;
        SDL_Rect fullscreenRect = { 0, 0, (int)screenWidth, (int)screenHeight };
        SDL_RenderCopy(renderer, resources->getTexture("pause", DEFAULT), NULL, &fullscreenRect);
        break;
    }
    case PLAY_STATE:
        SDL_Texture* background = resources->getTexture("background", DEFAULT);
        SDL_Texture* ground = resources->getTexture("ground", DEFAULT);
        SDL_Texture* mushroom = resources->getTexture("mushroom", SMALL_MUSHROOM);
        SDL_Texture* bigMushroom = resources->getTexture("mushroom", BIG_MUSHROOM);


        //render background
        SDL_Rect backgroundRect = { 0, 0, width, height };
        SDL_RenderCopyEx(renderer, background, NULL, &backgroundRect, 0, NULL, SDL_FLIP_NONE);

        //render mushroom
        SDL_Rect mushroomRect = { xMushroom, y + 10, width / 2 * 3, height };
        if (typeOfMushroom == BIG_MUSHROOM) {
            SDL_RenderCopyEx(renderer, bigMushroom, NULL, &mushroomRect, 0, NULL, SDL_FLIP_NONE);
        }
        else {
            SDL_RenderCopyEx(renderer, mushroom, NULL, &mushroomRect, 0, NULL, SDL_FLIP_NONE);
        }

        //render ground
        SDL_Rect groundRect1 = { x + width / 2 * 3, y, width / 2 * 3, height };
        SDL_Rect groundRect2 = { x, y, width / 2 * 3, height };
        SDL_RenderCopyEx(renderer, ground, NULL, &groundRect1, 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(renderer, ground, NULL, &groundRect2, 0, NULL, SDL_FLIP_NONE);
        break;

    }
}

void backGround::update(Clock* clock, Inputs *inputs, double velocity, Sound* sound) {
    switch (clock->gameState) {
    case OPENING_STATE:
    case START_STATE:
    case PAUSE_STATE:
    case GAME_OVER_STATE:
        break;

    case PLAY_STATE:
        if (!hasMushroom) {
            int randomMushroom = rand() % 100;
            if (randomMushroom > 60) {
                xMushroom = rand() % 500 + 1600;
                typeOfMushroom = SMALL_MUSHROOM;
                hasMushroom = true;
            }
            else {
                xMushroom = rand() % 200 + 1600;
                typeOfMushroom = BIG_MUSHROOM;
                hasMushroom = true;
            }
        }

        x -= velocity * VFIX;
        if (x < -width / 2 * 3)
        {
            x = 0;
        }
        xMushroom -= velocity * VFIX;
        if (xMushroom < -width / 2 * 3)
        {
            hasMushroom = false;
        }
        break;
    }
}


bool backGround::isAlive() {
    return true;
}

int backGround::getID() {
    return BACKGROUND_ID;
}

void backGround::die() {

}

#include "Threat.h"


#define WALL_DELAY 75.0f

Threat::Threat(std::vector<GameObjects*> *gameObjects) {
    this->gameObjects = gameObjects;
}

void Threat::createThreats(double *threatCoolDown) {
    if (*threatCoolDown == 0) {
        *threatCoolDown = WALL_DELAY;
        int randomX = rand() % 200 + 900;
        SDL_Rect hitbox = { randomX + 7, 275, 16, 100 };
        gameObjects->push_back(new Wall(randomX, 275, 30, 100, 900, 400, hitbox, gameObjects));
    }
}
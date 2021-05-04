#include "Threat.h"


#define THREAT_DELAY 150.0f

Threat::Threat(int screenWidth, int screenHeight, std::vector<GameObjects*> *gameObjects) {
    this->gameObjects = gameObjects;
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
}

void Threat::createThreats(double *threatCoolDown) {
    if (*threatCoolDown == 0) {
        *threatCoolDown = THREAT_DELAY;
        int randomX = rand() % 500 + screenWidth;
        int randomThreat = rand() % 100;
        if (randomThreat > 30) {
            SDL_Rect hitbox = { randomX, 520, 250, 200 };
            gameObjects->push_back(new Wolf(randomX, 515, 473, 215, screenWidth, screenHeight ,false, hitbox, gameObjects));
        }
        else {
            SDL_Rect hitbox = { randomX, 520, 250, 200 };
            gameObjects->push_back(new Wolf(randomX, 515, 473, 215, screenWidth, screenHeight, true, hitbox, gameObjects));
        }
    }
}
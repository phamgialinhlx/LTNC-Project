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
        int randomThreat = rand() % 100;
        if (randomThreat > 30) {
            int randomX = rand() % 500 + screenWidth;
            SDL_Rect hitbox = { randomX, 520, 300, 200 };
            gameObjects->push_back(new Wolf(randomX, 515, 473, 215, screenWidth, screenHeight, hitbox, gameObjects));
        }
        
        /*
        else {
            int randomX = rand() % 200 + 900;
            SDL_Rect hitbox = { randomX, 190, 90, 11 };
            gameObjects->push_back(new Wolf(randomX, 200, 100, 30, 900, 400, hitbox, gameObjects));
        }*/
    }
}
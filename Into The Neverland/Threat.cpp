#include "Threat.h"


#define WALL_DELAY 3.0f

Threat::Threat(std::vector<GameObjects*> *gameObjects) {
    this->gameObjects = gameObjects;
}

void Threat::createThreats(double *threatCoolDown) {
    if (*threatCoolDown == 0) {
        *threatCoolDown = WALL_DELAY;
        int randomY = rand() % 300;
        gameObjects->push_back(new Wall(100, 900, 275, 30, 100, 900, 400, gameObjects));
    }
}
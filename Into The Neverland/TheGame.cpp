#include "TheGame.h"
#include "Character.h"
#include "Background.h"
#include "Threat.h"

theGame::theGame()
{
    threats = new Threat(&gameObjects);
    threatCoolDown = 0;
    gameObjects.push_back(new backGround(100 , 0, 0, 0, 900, 400, &gameObjects));
    gameObjects.push_back(new character(0, 200, 200, 200, 30, 50, 900, 400, &gameObjects));
}

theGame::~theGame()
{
    for (int i = 0; i < gameObjects.size(); i++) {
        delete gameObjects[i];
        gameObjects[i] = NULL;
    }
}

std::vector<GameObjects*> *theGame::getGameObjects(){
    return &gameObjects;
}

double theGame::getTimeBetweenFrames() {
    return clock.getTimeBetweenFrames();
}

void theGame::update(Inputs *inputs) {

    clock.tick();

    
    threats->createThreats(&threatCoolDown);

    if (threatCoolDown > 0) {
        threatCoolDown -= clock.getTimeBetweenFrames();
        if (threatCoolDown < 0) {
            threatCoolDown = 0;
        }
    }

    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->update(clock.getTimeBetweenFrames(), inputs);
    }

    for (int i = 0; i < gameObjects.size(); i++) {
        if (!gameObjects[i]->isAlive()) {
            delete gameObjects[i];
            gameObjects[i] = NULL;
            gameObjects.erase(gameObjects.begin() + i);
            i -= 1;
        }
    }

}

void theGame::checkCollisions() {
    for (int i = 2; i < gameObjects.size(); i++) {
        if (gameObjects[i]->getID() == 2) {

        }
    }
}

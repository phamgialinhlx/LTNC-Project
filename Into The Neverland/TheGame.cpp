#include "TheGame.h"
#include "Background.h"
#include "Character.h"
#include "Graphics.h"


theGame::theGame()
{
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

    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->update(clock.getTimeBetweenFrames(), inputs);
    }
}
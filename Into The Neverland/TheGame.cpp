#include "TheGame.h"
#include "Background.h"
#include "Character.h"
#include "Graphics.h"


theGame::theGame()
{
    gameObjects.push_back(new backGround(10 , 0, 0, 0, 900, 400, &gameObjects));
    gameObjects.push_back(new character(0, 0, 200, 200, &gameObjects));
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

void theGame::update() {

    clock.tick();

    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->update(clock.getTimeBetweenFrames());
    }
}
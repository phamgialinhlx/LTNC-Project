#include "TheGame.h"
#include "Background.h"

const int theGame::screenHeight = 600, theGame::screenWidth = 1200;
const std::string theGame::windowTitle = "Into The Neverland: 9 + 1 = 11";

theGame::theGame()
{
    gameObjects.push_back(new backGround(1200,600, &gameObjects));
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
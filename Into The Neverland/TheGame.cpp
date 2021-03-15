#include "TheGame.h"
#include "Character.h"
#include "Background.h"
#include "Threat.h"
#include <iostream>

bool overlay(GameObjects* gameObject1, GameObjects* gameObject2) {
    bool collidsionOnAxisX = false;
    bool collidsionOnAxisY = false;
    double  minX1 = gameObject1->getX(),
        minY1 = gameObject1->getY(),
        maxX1 = gameObject1->getWidth() + gameObject1->getX(),
        maxY1 = gameObject1->getHeight() + gameObject1->getY();

    double  minX2 = gameObject2->getX(),
        minY2 = gameObject2->getY(),
        maxX2 = gameObject2->getWidth() + gameObject2->getX(),
        maxY2 = gameObject2->getHeight() + gameObject2->getY();
    if ((minX2 <= maxX1 && minX2 >= minX1) || (minX1 <= maxX2 && minX1 >= minX2)) {
        collidsionOnAxisX = true;
    }
    if ((minY2 <= maxY1 && minY2 >= minY1) || (minY1 <= maxY2 && minY1 >= minY2)) {
        collidsionOnAxisY = true;
    }

    return (collidsionOnAxisY && collidsionOnAxisX);
}

theGame::theGame()
{
    threats = new Threat(&gameObjects);
    threatCoolDown = 0;
    gameOver = false;
    gameObjects.push_back(new backGround(100 , 0, 0, 0, 900, 400, &gameObjects));
    gameObjects.push_back(new character(0, 200, 200, 200, 30, 50, 900, 400, &gameObjects));
}

theGame::~theGame()
{
    for (int i = 0; i < gameObjects.size(); i++) {
        delete gameObjects[i];
        gameObjects[i] = NULL;
    }

    delete threats;
    threats = NULL;
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
    
    checkCollisions();
    
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
            if (overlay(gameObjects[1], gameObjects[i])) {
                gameObjects[1]->die();
                gameOver = true;
            }
        }
    }
}


bool theGame::returnGameOver() {
    return gameOver;
}
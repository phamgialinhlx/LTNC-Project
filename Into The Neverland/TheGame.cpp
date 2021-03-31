#include "TheGame.h"
#include "Character.h"
#include "Background.h"
#include "Threat.h"
#include "Button.h"
#include "Score.h"
#include <iostream>
#include "GraphicSupport.h"

#define START_SCREEN 1

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

theGame::theGame(GraphicSupport* graphicSupport)
{
    this->graphicSupport = graphicSupport;
    threats = new Threat(&gameObjects);
    threatCoolDown = 0;
    gameOver = false;
    quit = false;
    gameObjects.push_back(new backGround(100 , 0, 0, 0, 900, 400, &gameObjects));
    gameObjects.push_back(new character(0, 200, 200, 625, 75, 100, 900, 400, &gameObjects));
    button = new Button(&gameObjects);
    gameObjects.push_back(button);
    score = new Score(30, 30, &gameObjects);
    gameObjects.push_back(score);
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

void theGame::update(Inputs *inputs, Clock *clock, Sound *sound) {
    
    
    if (clock->animationRunning) {
        graphicSupport->update(typeOfAnimation);
        clock->animationRunning = !graphicSupport->finish;

    }
    else {        
        if (gameOver || button->retry) {
            sound->pauseMusic();
            sound->stopMusic();
            restart();
            sound->playMusic();
        }

        if (!clock->pause && clock->start) {

            sound->resumeMusic();

            threats->createThreats(&threatCoolDown);

            if (threatCoolDown > 0) {
                threatCoolDown -= clock->getTimeBetweenFrames();
                if (threatCoolDown < 0) {
                    threatCoolDown = 0;
                }
            }

            for (int i = 0; i < gameObjects.size(); i++) {
                gameObjects[i]->update(clock, inputs);
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
            /* std::cout << "  [TheGame] pause: " << std::boolalpha << pause << std::endl;
                << "  [TheGame] clickCoolDown: " << clickCoolDown << std::endl
                << "  [TheGame] settingButton -> isClicked():" << settingButton->isClicked() << std::endl;*/

            //std::cout << button->setting << std::endl;
            if (button->setting) {
                //std::cout << button->setting << std::endl;
                sound->pauseMusic();
                clock->pause = true;
            }
            //std::cout << "  [TheGame] pause: " << std::boolalpha << pause << std::endl;
        }
        else {
            //std::cout << "  [TheGame] pause: " << std::boolalpha << pause << std::endl;
            
            if (inputs->isKeyDown(SDL_SCANCODE_SPACE) && !clock->start) {
                clock->start = true;
                clock->pause = false;
                clock->animationRunning = true;
                typeOfAnimation = START_SCREEN;
                sound->playMusic();
                //sound->resumeMusic();
            }
            button->update(clock, inputs);
        }

        quit = button->quit;
    }
}

void theGame::checkCollisions() {
    for (int i = 1; i < gameObjects.size(); i++) {
        for (int j = 1; j < gameObjects.size(); j++) {
            if (i != j) {
                if (gameObjects[i]->getID() == 1 && gameObjects[j]->getID() == 2) {
                    if (overlay(gameObjects[i], gameObjects[j])) {
                        gameObjects[i]->die();
                        gameOver = true;
                    }
                }
            }
        }
    }
}

void theGame::restart() {

    //delete all game objects
    for (int i = 0; i < gameObjects.size(); i++) {
        
            delete gameObjects[i];
            gameObjects[i] = NULL;
            gameObjects.erase(gameObjects.begin() + i);
            i -= 1;
        
    }
    //create new game objects
    gameOver = false;
    gameObjects.push_back(new backGround(100, 0, 0, 0, 900, 400, &gameObjects));
    gameObjects.push_back(new character(0, 0, 200, 325, 75, 100, 900, 400, &gameObjects));
    button = new Button(&gameObjects);
    gameObjects.push_back(button);
    score = new Score(30, 30, &gameObjects);
    gameObjects.push_back(score);
}

bool theGame::returnQuit() {
    return quit;
}




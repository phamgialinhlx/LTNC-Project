#include "TheGame.h"
#include "Character.h"
#include "Background.h"
#include "Threat.h"
#include "Menu.h"
#include "Score.h"
#include "Effects.h"
#include <iostream>



bool overlay(GameObjects* gameObject1, GameObjects* gameObject2) {
    bool collidsionOnAxisX = false;
    bool collidsionOnAxisY = false;
    double  minX1 = gameObject1->hitbox.x,
        minY1 = gameObject1->hitbox.y,
        maxX1 = gameObject1->hitbox.w + gameObject1->hitbox.x,
        maxY1 = gameObject1->hitbox.h + gameObject1->hitbox.y;

    double  minX2 = gameObject2->hitbox.x,
        minY2 = gameObject2->hitbox.y,
        maxX2 = gameObject2->hitbox.w + gameObject2->hitbox.x,
        maxY2 = gameObject2->hitbox.h + gameObject2->hitbox.y;
    if ((minX2 <= maxX1 && minX2 >= minX1) || (minX1 <= maxX2 && minX1 >= minX2)) {
        collidsionOnAxisX = true;
    }
    if ((minY2 <= maxY1 && minY2 >= minY1) || (minY1 <= maxY2 && minY1 >= minY2)) {
        collidsionOnAxisY = true;
    }

    return (collidsionOnAxisY && collidsionOnAxisX);
}

theGame::theGame(double screenWidth, double screenHeight)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    groundBaseSpeed = 12;
    quit = false;
    speedFix = 0;

    gameObjects.push_back(new backGround(0, 0, screenWidth, screenHeight, &gameObjects));
    SDL_Rect characterHitbox{ 235, 525, 105, 160 };
    gameObjects.push_back(new character(200, 525, 170, 200, screenWidth, screenHeight, characterHitbox, &gameObjects));
    score = new Score(30, 30, &gameObjects);
    gameObjects.push_back(score);
    threats = new Threat(screenWidth, screenHeight, &gameObjects);
    menu = new Menu(&gameObjects, screenWidth, screenHeight);
    gameObjects.push_back(menu);
    
    
    
    //start(screenWidth, screenHeight);
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

void theGame::update(Inputs *inputs, Clock *clock, Sound *sound, Effects* effects) {
    switch (clock->gameState) {
    case OPENING_STATE:
        if (effects->finish) {
            effects->effectType = FADE;
            clock->gameState = START_STATE;
        }
        break;
    case START_STATE:
        menu->update(clock, inputs, (groundBaseSpeed + speedFix) * clock->deltaT, sound);
        if (clock->gameState == PLAY_STATE) {
            effects->effectType = FLASH;

        }
        break;
    case PLAY_STATE:
        threats->createThreats(&threatCoolDown);
        if (threatCoolDown > 0) {
            threatCoolDown -= clock->deltaT;
            if (threatCoolDown < 0) {
                threatCoolDown = 0;
            }
        }
        //std::cout << gameObjects.size() << std::endl;
        for (int i = 0; i < gameObjects.size(); i++) {
            gameObjects[i]->update(clock, inputs, (groundBaseSpeed + speedFix) * clock->deltaT, sound);
        }

        if (checkCollisions(sound, clock)) {
            sound->pauseMusic();
            clock->gameState = GAME_OVER_STATE;
        }
        for (int i = 0; i < gameObjects.size(); i++) {
            if (!gameObjects[i]->isAlive()) {
                delete gameObjects[i];
                gameObjects[i] = NULL;
                gameObjects.erase(gameObjects.begin() + i);
                i -= 1;
            }
        }

        if (speedFix <= 1.3 * groundBaseSpeed && !clock->pause)//speed fix limit
        {
            speedFix += 0.0025;
        }

        //std::cout << (groundBaseSpeed + speedFix) * 1.2 << std::endl;
        
        //if (menu->setting) {
        //    //std::cout << button->setting << std::endl;
        //    sound->pauseMusic();
        //    clock->pause = true;
        //    menu->menuType = 2; //SETTING_SCREEN
        //}
        break;

    case PAUSE_STATE:
        
        break;
    case GAME_OVER_STATE:
        
        break;
    }
    quit = clock->quit;
}

bool theGame::checkCollisions(Sound *sound, Clock *clock) {
    for (int i = 1; i < gameObjects.size(); i++) {
        for (int j = 1; j < gameObjects.size(); j++) {
            if (i != j) {
                if (gameObjects[i]->getID() == 1 && gameObjects[j]->getID() == 2) {
                    if (overlay(gameObjects[i], gameObjects[j])) {
                        gameObjects[i]->die();
                        return true;
                    }
                }
            }
        }
    }
    return false;
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
    //start(screenWidth, screenHeight);
    //menu->menuType = 0;
}

void theGame::start(double screenWidth, double screenHeight) {
    //groundBaseSpeed = 12;
    //quit = false;
    //speedFix = 0;

    //gameObjects.push_back(new backGround(0, 0, screenWidth, screenHeight, &gameObjects));
    //SDL_Rect characterHitbox{ 235, 525, 105, 160 };
    //gameObjects.push_back(new character(200, 525, 170, 200, screenWidth, screenHeight, characterHitbox, &gameObjects));
    //menu = new Menu(&gameObjects, screenWidth, screenHeight);
    //gameObjects.push_back(menu);
    //score = new Score(30, 30, &gameObjects);
    //gameObjects.push_back(score);
}

bool theGame::returnQuit() {
    return quit;
}




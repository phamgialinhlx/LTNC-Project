#include "TheGame.h"
#include "Character.h"
#include "Background.h"
#include "Threat.h"
#include "Menu.h"
#include "Score.h"
#include <iostream>

#define START_SCREEN 1

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
    
    threats = new Threat(&gameObjects);
    threatCoolDown = 0;
    gameOver = false;
    groundBaseSpeed = 7;
    quit = false;
    speedFix = 0;
    gameObjects.push_back(new backGround(0, 0, screenWidth, screenHeight, &gameObjects));
    SDL_Rect characterHitbox {220, 275, 55, 80};
    gameObjects.push_back(new character(200, 275, 85, 100, screenWidth, screenHeight, characterHitbox,&gameObjects));
    menu = new Menu(&gameObjects);
    gameObjects.push_back(menu);
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
    
    
    /*if (clock->animationRunning) {
        graphicSupport->update(typeOfAnimation);
        clock->animationRunning = !graphicSupport->finish;

    }
    else {  */      
        if (gameOver || menu->retry) {
            sound->pauseMusic();
            sound->stopMusic();
            restart();
            sound->playMusic();
        }

        if (!clock->pause && clock->start) {

            sound->resumeMusic();

            threats->createThreats(&threatCoolDown);

            if (threatCoolDown > 0) {
                threatCoolDown -= clock->deltaT;
                if (threatCoolDown < 0) {
                    threatCoolDown = 0;
                }
            }

            for (int i = 0; i < gameObjects.size(); i++) {
                gameObjects[i]->update(clock, inputs, (groundBaseSpeed + speedFix) * clock->deltaT);
            }

            checkCollisions(menu, sound, clock);

            for (int i = 0; i < gameObjects.size(); i++) {
                if (!gameObjects[i]->isAlive()) {
                    delete gameObjects[i];
                    gameObjects[i] = NULL;
                    gameObjects.erase(gameObjects.begin() + i);
                    i -= 1;
                }
            }
            
            if (menu->setting) {
                //std::cout << button->setting << std::endl;
                sound->pauseMusic();
                clock->pause = true;
                menu->menuType = 2; //SETTING_SCREEN
            }
            //std::cout << "  [TheGame] pause: " << std::boolalpha << pause << std::endl;
        }
        else {
            
            menu->update(clock, inputs, (groundBaseSpeed + speedFix) * clock->deltaT);
            
            if (clock->start) {
                sound->playMusic(); 
            }
        }

        quit = menu->quit;
    //}

    if (speedFix <= 1.3 * groundBaseSpeed && !clock->pause)//speed fix limit
    {
        speedFix += 0.0025;
    }
    //std::cout << (groundBaseSpeed + speedFix) * 1.2 << std::endl;
}

void theGame::checkCollisions(Menu* menu, Sound *sound, Clock *clock) {
    for (int i = 1; i < gameObjects.size(); i++) {
        for (int j = 1; j < gameObjects.size(); j++) {
            if (i != j) {
                if (gameObjects[i]->getID() == 1 && gameObjects[j]->getID() == 2) {
                    if (overlay(gameObjects[i], gameObjects[j])) {
                        gameObjects[i]->die();
                        sound->pauseMusic();
                        clock->pause = true;
                        menu->menuType = 3; //GAME_OVER
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
    speedFix = 0;
    gameOver = false;
    gameObjects.push_back(new backGround(0, 0, screenWidth, screenHeight, &gameObjects));
    SDL_Rect characterHitbox{ 220, 325, 55, 80 };
    gameObjects.push_back(new character(200, 275, 85, 100, screenWidth, screenHeight, characterHitbox, &gameObjects));
    menu = new Menu(&gameObjects);
    gameObjects.push_back(menu);
    menu->menuType = 0;
    score = new Score(30, 30, &gameObjects);
    gameObjects.push_back(score);
}

bool theGame::returnQuit() {
    return quit;
}




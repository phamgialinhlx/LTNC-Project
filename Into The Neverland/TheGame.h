#pragma once

#ifndef THE_GAME_H
#define THE_GAME_H

#include <SDL.h>
#include <string>
#include <iostream>
#include <vector>

#include "GameObjects.h"
#include "Inputs.h"
#include "Clock.h"


class GameObjects;
class Threat;
class Button;

class theGame
{
private:
	
	Threat* threats;
	Button *button;
	double threatCoolDown;
	double clickCoolDown;
	bool gameOver;
	std::vector <GameObjects*> gameObjects;

	//void renderTransparentBlackBG(SDL_Renderer* renderer, Resources* resources);

public:
	theGame();
	~theGame();

	std::vector<GameObjects*> *getGameObjects();
	void update(Inputs *inputs, Clock *clock);
	//double getTimeBetweenFrames();
	//void startScreen();
	void checkCollisions();
	bool returnGameOver();
};



#endif // !THE_GAME

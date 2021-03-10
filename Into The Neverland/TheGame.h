#pragma once

#ifndef THE_GAME_H
#define THE_GAME_H

#include <SDL.h>
#include <string>
#include <iostream>
#include <vector>
#include "GameObjects.h"
#include "Clock.h"
#include "Inputs.h"

class GameObjects;

class theGame
{
private:
	Clock clock;
	std::vector <GameObjects*> gameObjects;

public:
	theGame();
	~theGame();

	std::vector<GameObjects*> *getGameObjects();
	void update(Inputs *inputs);
	double getTimeBetweenFrames();

};



#endif // !THE_GAME

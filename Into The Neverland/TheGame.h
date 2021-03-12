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

class theGame
{
private:
	Clock clock;
	Threat *threats;
	double threatCoolDown;
	std::vector <GameObjects*> gameObjects;

public:
	theGame();
	~theGame();

	std::vector<GameObjects*> *getGameObjects();
	void update(Inputs *inputs);
	double getTimeBetweenFrames();
	void checkCollisions();
};



#endif // !THE_GAME

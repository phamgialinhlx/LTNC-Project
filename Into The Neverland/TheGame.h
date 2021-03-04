#pragma once

#ifndef THE_GAME_H
#define THE_GAME_H

#include <SDL.h>
#include <string>
#include <iostream>
#include <vector>
#include "GameObjects.h"


class GameObjects;

class theGame
{
private:
	static const int screenWidth, screenHeight;
	static const std::string windowTitle;

	std::vector <GameObjects*> gameObjects;

public:
	theGame();
	~theGame();

	std::vector<GameObjects*> *getGameObjects();
};



#endif // !THE_GAME

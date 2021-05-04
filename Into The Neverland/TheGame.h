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
#include "Sound.h"


class GameObjects;
class Threat;
class Menu;
class Score;
class Effects;
class GraphicSupport;

class theGame
{
private:
	
	Threat* threats;
	Menu *menu;
	Score* score;
	double threatCoolDown;
	double clickCoolDown;

	double screenWidth;
	double screenHeight;

	double speedFix;
	double groundBaseSpeed;

	std::vector <GameObjects*> gameObjects;

public:
	theGame(double screenWidth, double screenHeight);
	~theGame();

	std::vector<GameObjects*> *getGameObjects();
	void update(Inputs *inputs, Clock *clock, Sound *sound, Effects* effects);
	bool checkCollisions(Sound *sound, Clock *clock);
	void start(double screenWidth, double screenHeight);
	void restart();

};



#endif // !THE_GAME

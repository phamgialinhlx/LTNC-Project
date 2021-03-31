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
class Button;
class Score;
class GraphicSupport;

class theGame
{
private:
	
	Threat* threats;
	Button *button;
	Score* score;
	GraphicSupport* graphicSupport;
	double threatCoolDown;
	double clickCoolDown;
	int typeOfAnimation;
	bool gameOver, quit;
	std::vector <GameObjects*> gameObjects;

	//void renderTransparentBlackBG(SDL_Renderer* renderer, Resources* resources);

public:
	theGame(GraphicSupport* graphicSupport);
	~theGame();

	std::vector<GameObjects*> *getGameObjects();
	void update(Inputs *inputs, Clock *clock, Sound *sound);
	void checkCollisions();
	void restart();
	bool returnQuit();
};



#endif // !THE_GAME

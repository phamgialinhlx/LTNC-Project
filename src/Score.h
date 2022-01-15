
#pragma once
#ifndef TEXT_H
#define TEXT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <cmath>
#include "Clock.h"
#include "Inputs.h"
#include "GameObjects.h"

class GameObjects;
class Resources;


class Score : public GameObjects
{

private:
	int bestScore;
	std::vector<GameObjects*>* gameObjects;
	

public:

	double characterLifeTime;


	Score(int x, int y, std::vector<GameObjects*>* gameObjects);
	~Score();

	void render(SDL_Renderer* renderer, Resources* resources, Clock* clock);
	void update(Clock* clock, Inputs* inputs, double velocity, Sound* sound);

	bool isAlive();
	int getID();
	void die();
};

#endif
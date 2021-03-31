
#pragma once
#ifndef TEXT_H
#define TEXT_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <cmath>
#include "Clock.h"
#include "Resources.h"
#include "Inputs.h"
#include "GameObjects.h"

class GameObjects;
class Resources;


class Text : public GameObjects
{

private:
	
	std::vector<GameObjects*>* gameObjects;

public:

	double characterLifeTime;
	

	Text(int x, int y, std::vector<GameObjects*>* gameObjects);

	void render(SDL_Renderer* renderer, Resources* resources, Clock* clock);
	void update(Clock* clock, Inputs* inputs);

	bool isAlive();
	int getID();
	void die();

	void renderScore(SDL_Renderer* renderer, Resources* resources, Clock* clock);
	//void renderText(const char* theText, SDL_Renderer* renderer, Clock* clock);
	void renderNote(SDL_Renderer* renderer, Resources* resources, Clock* clock);
};

#endif
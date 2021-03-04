#pragma once
#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "TheGame.h"
#include "Resources.h"

class theGame;
	
class GameObjects
{
protected:
	double x, y;
	int width;
	int height;

public:
	double getX();
	double getY();

	GameObjects(double x, double y, int width, int height);
	~GameObjects();

	virtual void render(SDL_Renderer* renderer, Resources* resources) = 0;
	
};


#endif
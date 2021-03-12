#pragma once
#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "TheGame.h"
#include "Resources.h"
#include "Inputs.h"

// ID BACKGROUND: 0
// ID CHARACTER: 1
// ID THREAT: 2

class theGame;
	
class GameObjects
{
protected:
	double x, y;
	double width;
	double height;

public:
	GameObjects(double x, double y, int width, int height);
	~GameObjects();

	double getX();
	double getY();

	virtual void render(SDL_Renderer* renderer, Resources* resources, double timeBetweenFrames) = 0;
	virtual void update(double timeBetweenFrames, Inputs *inputs) = 0;
	virtual bool isAlive() = 0;
	virtual int getID() = 0;
	
};


#endif
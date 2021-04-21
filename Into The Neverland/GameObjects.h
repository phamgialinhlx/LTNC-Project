#pragma once
#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "TheGame.h"
#include "Resources.h"
#include "Sound.h"
#include "Inputs.h"
#include "Clock.h"

enum GAME_OBJECTS_ID {
	BACKGROUND_ID,
	CHARACTER_ID,
	THREAT_ID,
	TEXT_ID,
	BUTTON_ID
};


class theGame;
	
class GameObjects
{
protected:
	double x, y;
	double width;
	double height;
	double screenWidth, screenHeight;
	
public:
	SDL_Rect hitbox;
	GameObjects(double x, double y, double width, double height, 
				double screenWidth, double screenHeight, SDL_Rect hitbox);
	~GameObjects();

	double getX();
	double getY();
	double getWidth();
	double getHeight();
	
	void renderHitbox(SDL_Renderer* renderer);
	virtual void render(SDL_Renderer* renderer, Resources* resources, Clock* clock) = 0;
	virtual void update(Clock* clock, Inputs *inputs, double veloctity, Sound* sound) = 0;
	virtual bool isAlive() = 0;
	virtual int getID() = 0;
	virtual void die() = 0;
	
};


#endif
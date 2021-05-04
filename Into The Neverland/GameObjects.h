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
	BUTTON_ID,
	PARTICLE_ID,
	MENU_ID,
	SCORE_ID
};
 

class theGame;
	
class GameObjects
{
protected:
	const double gravity = -0.8f;
	double x, y;
	double width;
	double height;
	double screenWidth, screenHeight;
	
public:
	SDL_Rect hitbox;
	GameObjects(double x, double y, double width, double height, 
				double screenWidth, double screenHeight, SDL_Rect hitbox);
	virtual ~GameObjects();

	double getX();
	double getY();
	double getWidth();
	double getHeight();
	
	
	void renderHitbox(SDL_Renderer* renderer);
	virtual void render(SDL_Renderer* renderer, Resources* resources, Clock* clock) {}
	virtual void update(Clock* clock, Inputs *inputs, double veloctity, Sound* sound) {}
	virtual bool isAlive() { return true; }
	virtual int getID() { return -1; }
	virtual void die() {}
	
};


#endif
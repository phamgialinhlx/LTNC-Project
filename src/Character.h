#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL2/SDL.h>
#include <vector>
#include "GameObjects.h"
#include "Resources.h"
#include "Inputs.h"
#include "Particle.h"

class Character : public GameObjects
{
private:
	std::vector<GameObjects*>* gameObjects;
	double vY, ground;
	bool jump, alive, fall;
	int frame;

public:
	Character(double x, double y, double width, double height, double screenWidth, 
			  double screenHeight, SDL_Rect hitbox, std::vector<GameObjects*>* gameObjects);
	void render(SDL_Renderer* renderer, Resources* resources, Clock* clock);
	void update(Clock* clock, Inputs *inputs, double velocity, Sound *sound);
	bool isAlive();
	int getID();
	void die();
	int chooseFrames();
};

#endif // !CHARACTER_H

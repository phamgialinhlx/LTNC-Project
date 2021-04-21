#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL.h>
#include <vector>
#include "GameObjects.h"
#include "Resources.h"
#include "Inputs.h"


class character : public GameObjects
{
private:
	std::vector<GameObjects*>* gameObjects;

	double gravity, vY, count;
	bool jump, alive;
	int frame;

public:
	character(double x, double y, double width, double height, double screenWidth, 
			  double screenHeight, SDL_Rect hitbox, std::vector<GameObjects*>* gameObjects);
	void render(SDL_Renderer* renderer, Resources* resources, Clock* clock);
	void update(Clock* clock, Inputs *inputs, double velocity, Sound *sound);
	bool isAlive();
	int getID();
	void die();
};

#endif // !CHARACTER_H

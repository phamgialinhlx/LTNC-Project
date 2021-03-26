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

	double vX, vY;
	bool alive;
	int characterTimer;

public:
	character(double vX, double vY, double x, double y, double width, double height,
			  double screenWidth, double screenHeight, std::vector<GameObjects*>* gameObjects);
	void render(SDL_Renderer* renderer, Resources* resources, Clock* clock);
	void update(double timeBetweenFrames, Inputs *inputs);
	bool isAlive();
	int getID();
	void die();
};

#endif // !CHARACTER_H

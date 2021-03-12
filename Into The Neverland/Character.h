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
	double x, y;
	double screenWidth, screenHeight;
	double width, height;
	bool alive;

public:
	character(double vX, double vY, double x, double y, double width, double height,
			  double screenWidth, double screenHeight, std::vector<GameObjects*>* gameObjects);
	void render(SDL_Renderer* renderer, Resources* resources, double timeBetweenFrames);
	void update(double timeBetweenFrames, Inputs *inputs);
	bool isAlive();
	int getID();
};

#endif // !CHARACTER_H

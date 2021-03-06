#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL.h>
#include "GameObjects.h"
#include "Resources.h"
#include <vector>

class GameObjects;

class character : public GameObjects
{
private:
	std::vector<GameObjects*>* gameObjects;

	double vX, vY;
	double x, y;
	bool alive;

public:
	character(double vX, double vY, double x, double y, std::vector<GameObjects*>* gameObjects);
	void render(SDL_Renderer* renderer, Resources* resources, double timeBetweenFrames);
	void update(double timeBetweenFrames);
	bool isAlive();
};

#endif // !CHARACTER_H

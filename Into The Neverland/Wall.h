#pragma once
#ifndef WALL_H
#define WALL_H

#include <SDL.h>
#include "GameObjects.h"


class Wall : public GameObjects
{
private:
	std::vector<GameObjects*> *gameObjects;

	double velocity;
	bool alive;

public:
	Wall(double velocity, double x, double y, double width, double height,
		double screenWidth, double screenHeight, std::vector<GameObjects*>* gameObjects);
	void render(SDL_Renderer* renderer, Resources* resources, Clock* clock);
	void update(double timeBetweenFrames, Inputs* inputs);
	bool isAlive();
	int getID();
	void die();
};

#endif // !WALL_H

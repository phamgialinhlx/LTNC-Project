#pragma once
#pragma once
#ifndef WOLF_H
#define WOLF_H

#include <SDL.h>
#include "GameObjects.h"


class Wolf : public GameObjects
{
private:
	std::vector<GameObjects*>* gameObjects;

	double velocity;
	bool alive;
	int frame;

public:
	Wolf(double x, double y, double width, double height, double screenWidth,
		double screenHeight, SDL_Rect hitbox, std::vector<GameObjects*>* gameObjects);
	void render(SDL_Renderer* renderer, Resources* resources, Clock* clock);
	void update(Clock* clock, Inputs* inputs, double velocity, Sound *sound);
	bool isAlive();
	int getID();
	void die();
};

#endif // !WALL_H

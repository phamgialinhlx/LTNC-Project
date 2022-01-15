#pragma once
#pragma once
#ifndef WOLF_H
#define WOLF_H

#include <SDL2/SDL.h>
#include "GameObjects.h"
#include "Particle.h"


class Wolf : public GameObjects
{
private:
	std::vector<GameObjects*>* gameObjects;

	double vY, ground;
	bool alive;
	int frame;
	bool willJump;
	bool jump;
	int count;

public:
	Wolf(double x, double y, double width, double height, double screenWidth,
		double screenHeight, bool willJump, SDL_Rect hitbox, std::vector<GameObjects*>* gameObjects);
	~Wolf() {}
	void render(SDL_Renderer* renderer, Resources* resources, Clock* clock);
	void update(Clock* clock, Inputs* inputs, double velocity, Sound *sound);
	bool isAlive();
	int getID();
	void die();

	int chooseFrames();
};

#endif // !WALL_H

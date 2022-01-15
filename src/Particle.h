#pragma once
#ifndef PARTICLE_H
#define PARTICLE_H

#include <SDL2/SDL.h>
#include <vector>
#include "GameObjects.h"
#include "Resources.h"
#include "Inputs.h"

#define NUM_PARTICLES 4
#define ACCELERATION -0.2f
#define DANGER_SCALE 0.95f
#define POW_SCALE 0.1f

class Particle : public GameObjects
{
private:
	double opacity;
	double scale;
	double vX, vY;
	std::string particleName;

public:
	Particle(double x, double y, double vX, double vY, double scale, std::string particleName);
	void render(SDL_Renderer* renderer, Resources* resources, Clock* clock);
	void update(Clock* clock, Inputs* inputs, double veloctity, Sound* sound);
	bool isAlive();
	int getID();
	void die() {}
};

#endif // !CHARACTER_H

#pragma once
#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "GameObjects.h"
#include "Resources.h"
#include "Inputs.h"
#include <string>

class GameObjects;
class Resources;


class backGround : public GameObjects{
private:

	double vX;
	double vY;

	double typeOfMushroom;
	double xMushroom;
	bool hasMushroom;

	std::vector<GameObjects*> *gameObjects;

public:

	backGround(double x, double y, double width, double height, std::vector<GameObjects*>* gameObjects);
	void render(SDL_Renderer* renderer, Resources* resources, Clock* clock);

	void update(Clock* clock, Inputs *inputs, double velocity, Sound* sound);
	bool isAlive();
	int getID();
	void die();
};

#endif // !BACKGROUND_H

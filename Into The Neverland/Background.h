#pragma once
#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "GameObjects.h"
#include "Resources.h"
#include "Clock.h"
#include "Inputs.h"
#include <string>

class GameObjects;
class Resources;


class backGround : public GameObjects{
private:

	double vX;
	double vY;

	double x;
	double y;

	double width;
	double height;

	std::vector<GameObjects*> *gameObjects;

public:
	double getX();
	double getY();

	backGround(double vX, double vY, double x, double y, double width, double height, std::vector<GameObjects*>* gameObjects);
	void render(SDL_Renderer* renderer, Resources* resources, double timeBetweenFrames);

	void update(double timeBetweenFrames, Inputs *inputs);

	int getWidth();
	int getHeight();
};

#endif // !BACKGROUND_H

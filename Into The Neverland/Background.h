#pragma once
#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "GameObjects.h"
#include "Resources.h"
#include "Clock.h"
#include <string>

class GameObjects;
class Resources;
class clock;

class backGround : public GameObjects{
private:

	int vX;
	int vY;

	int x;
	int y;

	int width;
	int height;

	int scrollingOffset;

	std::vector<GameObjects*> *gameObjects;

public:
	double getX();
	double getY();

	backGround(int vX, int vY, int x, int y, int width, int heigth, std::vector<GameObjects*>* gameObjects);
	void render(SDL_Renderer* renderer, Resources* resources, double timeBetweenFrames);

	void update(double timeBetweenFrames);

	int getWidth();
	int getHeight();
};

#endif // !BACKGROUND_H

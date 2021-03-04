#pragma once
#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "GameObjects.h"
#include "Resources.h"
#include <string>

class GameObjects;
class Resources;

class backGround : public GameObjects{
private:
	int width;
	int height;

	std::vector<GameObjects*> *gameObjects;

public:
	double getX();
	double getY();

	backGround(int width, int heigth, std::vector<GameObjects*>* gameObjects);
	void render(SDL_Renderer* renderer, Resources* resources);
};

#endif // !BACKGROUND_H

#pragma once
#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include <SDL.h>
#include <string>
class GameObjects
{
protected:
	double x, y;
	int width;
	int height;

	SDL_Texture* texture;

public:
	double getX();
	double getY();

	double getCenterX();
	double getCenterY();

	GameObjects();
	~GameObjects();

	bool getTexture(std::string filepath);
	void render(int x, int y, SDL_Rect* clip = NULL);
	void free();
};


#endif
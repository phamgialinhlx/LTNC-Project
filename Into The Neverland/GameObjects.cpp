#include "GameObjects.h"

GameObjects::GameObjects(double x, double y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

GameObjects::~GameObjects()
{
	
}

double GameObjects::getX() {
	return x;
}

double GameObjects::getY() {
	return y;
}




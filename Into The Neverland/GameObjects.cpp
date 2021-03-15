#include "GameObjects.h"

GameObjects::GameObjects(double x, double y, double width, double height, double screenWidth, double screenHeight)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
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

double GameObjects::getWidth() {
	return width;
}

double GameObjects::getHeight() {
	return height;
}


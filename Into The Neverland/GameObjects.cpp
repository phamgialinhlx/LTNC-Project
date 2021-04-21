#include "GameObjects.h"

GameObjects::GameObjects(double x, double y, double width, double height, 
						 double screenWidth, double screenHeight, SDL_Rect hitbox)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	this->hitbox = hitbox;
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

void GameObjects::renderHitbox(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(renderer, &hitbox);
}

#include "Character.h"

character::character(double vX, double vY, double x, double y, std::vector<GameObjects*>* gameObjects)
					:GameObjects(x, y, width, height) 
{
	this->vX = vX;
	this->vY = vY;
	this->x = x;
	this->y = y;
	alive = true;
	this->gameObjects = gameObjects;
}

void character::render(SDL_Renderer* renderer, Resources* resources, double timeBetweenFrames) {
	SDL_Texture* texture;
	texture = resources->getTexture("character");

	int textureWidth, textureHeight;
	SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
	SDL_Rect dst = {
		(int)x,
		(int)y,
		textureWidth,
		textureHeight
	};

	SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0,
		NULL, SDL_FLIP_NONE);
}

bool character::isAlive() {
	return alive;
}

void character::update(double timeBetweenFrames) {

}
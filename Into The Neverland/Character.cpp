#include "Character.h"

character::character(double vX, double vY, double x, double y, double width, double height, 
					 double screenWidth, double screenHeight, std::vector<GameObjects*>* gameObjects)
					:GameObjects(x, y, width, height, screenWidth, screenHeight) 
{
	this->vX = vX;
	this->vY = vY;
	alive = true;
	this->gameObjects = gameObjects;
}

void character::render(SDL_Renderer* renderer, Resources* resources, double timeBetweenFrames) {
	SDL_Texture* texture;
	texture = resources->getTexture("character");

	SDL_Rect dst = {
		(int)x,
		(int)y,
		width,
		height
	};

	SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0,
		NULL, SDL_FLIP_NONE);
}

bool character::isAlive() {
	return alive;
}

void character::update(double timeBetweenFrames, Inputs *inputs) {

	if (inputs->isKeyDown(SDL_SCANCODE_SPACE)) {
		y -= timeBetweenFrames * vY;
	}
	else {
		y += timeBetweenFrames * vY;
	}
	
	if (y + height > screenHeight - 25) {
		y = screenHeight - 25 - height;
	}

	if (y < 25) {
		y = 25;
	}


}

int character::getID() {
	return 1;
}

void character::die() {
	alive = false;
}
#include "Character.h"
#include <iostream>

#define CHARACTER_TIMER 60

character::character(double vX, double vY, double x, double y, double width, double height, 
					 double screenWidth, double screenHeight, std::vector<GameObjects*>* gameObjects)
					:GameObjects(x, y, width, height, screenWidth, screenHeight) 
{
	this->vX = vX;
	this->vY = vY;
	alive = true;
	this->gameObjects = gameObjects;
	characterTimer = CHARACTER_TIMER;
}

int chooseFrames(int n) {
	if (n >= 51) {
		return 0;
	}
	if (n >= 41) {
		return 1;
	}
	if (n >= 31) {
		return 2;
	}
	if (n >= 21) {
		return 3;
	}
	if (n >= 11) {
		return 4;
	}
	if (n >= 1) {
		return 5;
	}
}

void character::render(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
	SDL_Texture* texture;

	texture = resources->getTexture("character", chooseFrames(characterTimer));

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

void character::update(Clock* clock, Inputs *inputs) {

	if (inputs->isKeyDown(SDL_SCANCODE_SPACE)){
		//vY += 50;
		y -= clock->getTimeBetweenFrames() * vY;
	}
	else {
		//vY = 200;
		y += clock->getTimeBetweenFrames() * vY;
	}
	
	if (y + height > screenHeight - 25) {
		y = screenHeight - 25 - height;
	}

	if (y < 25) {
		y = 25;
	}

	if (characterTimer == 0) {
		characterTimer = CHARACTER_TIMER;
	}
	characterTimer--;
}

int character::getID() {
	return 1;
}

void character::die() {
	alive = false;
}
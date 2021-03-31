#include "Character.h"
#include <iostream>

#define CHARACTER_TIMER 50

character::character(double vX, double vY, double x, double y, double width, double height, 
					 double screenWidth, double screenHeight, std::vector<GameObjects*>* gameObjects)
					:GameObjects(x, y, width, height, screenWidth, screenHeight) 
{
	this->vX = vX;
	this->vY = vY;
	alive = true;
	jump = false;
	this->gameObjects = gameObjects;
	characterTimer = CHARACTER_TIMER;
}

int chooseFrames(int n) {
	if (n >= 45) {
		return 0;
	}
	if (n >= 40) {
		return 1;
	}
	if (n >= 35) {
		return 2;
	}
	if (n >= 30) {
		return 3;
	}
	if (n >= 25) {
		return 4;
	}
	if (n >= 20) {
		return 5;
	}
	if (n >= 15) {
		return 6;
	}
	if (n >= 10) {
		return 7;
	}
	if (n >= 5) {
		return 8;
	}
	if (n >= 0) {
		return 9;
	}
	
}

void character::render(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
	SDL_Texture* texture;

	texture = resources->getTexture("characterRun", chooseFrames(characterTimer));

	//std::cout << "[character] frame:" << chooseFrames(characterTimer) << std::endl;

	SDL_Rect dst = {
		(int)x,
		y,
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
	
	//std::cout << x << "_" << y << std::endl;
	if (!jump) {
		if (inputs->isKeyDown(SDL_SCANCODE_SPACE)) {
			vY = 10;
			jump = true;
		}
	}
	else {
		if (vY == 0) {
			y += 10;
			if (y == screenHeight - 25 - height) {
				jump = false;
			}
		}
		if (vY > 0) {
			if (y < 100) {
				vY -= 1;
			}
			else {
				y -= vY;
			}
		}
		
	}
	std::cout << vY << std::endl;
	
	if (y + height > screenHeight - 25) {
		y = screenHeight - 25 - height;
	}

	if (y < 25) {
		y = 25;
	}

	characterTimer--;

	if (characterTimer < 0) {
		characterTimer = CHARACTER_TIMER;
	}
	
}

int character::getID() {
	return 1;
}

void character::die() {
	alive = false;
}
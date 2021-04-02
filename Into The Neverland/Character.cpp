#include "Character.h"
#include <iostream>

#define RUN_TIMER 50

character::character(double x, double y, double width, double height, double screenWidth, 
					 double screenHeight, SDL_Rect hitbox ,std::vector<GameObjects*>* gameObjects)
					:GameObjects(x, y, width, height, screenWidth, screenHeight, hitbox) 
{
	gravity = -0.78f;
	vY = 0;
	alive = true;
	jump = false;
	this->gameObjects = gameObjects;
	characterTimer = RUN_TIMER;
	count = 0;
}

int chooseFrames(bool jump, int n) {
	if (!jump){
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
	else {
		if (n >= 47) {
			return 0;
		}
		if (n >= 44) {
			return 1;
		}
		if (n >= 41) {
			return 2;
		}
		if (n >= 38) {
			return 3;
		}
		if (n >= 35) {
			return 4;
		}
		if (n >= 31) {
			return 5;
		}
		if (n >= 27) {
			return 6;
		}
		if (n >= 23) {
			return 7;
		}
		if (n >= 19) {
			return 8;
		}
		if (n >= 15) {
			return 9;
		}
		if (n >= 11) {
			return 10;
		}
		if (n >= 7) {
			return 11;
		}
		if (n >= 4) {
			return 12;
		}
		if (n >= 2) {
			return 13;
		}
		if (n >= 0) {
			return 14;
		}
	}
}

void character::render(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
	SDL_Texture* texture;

	if (jump) {
		texture = resources->getTexture("characterJump", chooseFrames(jump, characterTimer));
	}
	else {
		texture = resources->getTexture("characterRun", chooseFrames(jump, characterTimer));
	}
	

	//std::cout << "[character] frame:" << chooseFrames(characterTimer) << std::endl;

	SDL_Rect dst = {
		x,
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

void character::update(Clock* clock, Inputs *inputs, double velocity) {
	
	//std::cout << "[Character] y: " << y << std::endl;
	//std::cout << "[Character] screenHeight - 25 - height: " << screenHeight - 25 - height << std::endl;
	//std::cout << "[Character] vY: " << vY << std::endl;	
	//if (inputs->isKeyDown(SDL_SCANCODE_SPACE)) {  }
	if (y == screenHeight - 25 - height && vY == 0 && !jump && inputs->isKeyDown(SDL_SCANCODE_SPACE)) { //only jump when on the ground
		vY = 18;
		jump = true;
		count = 0;
		characterTimer = 47;
	}
	//std::cout << y << std::endl;
	//std::cout << std::boolalpha << jump << std::endl;
	if (jump) {
		
		if ((y == screenHeight - 25 - height && vY > 0) || y < 275 ) {
			y -= vY * clock->deltaT + 0.5f * gravity * clock->deltaT * clock->deltaT;
			hitbox.y -= vY * clock->deltaT + 0.5f * gravity * clock->deltaT * clock->deltaT;
			//y = y0 + v0*t + (a*t*t)/2
			vY += gravity * clock->deltaT;
			//vy = v0 + a*t
			count++;
		}
	}
	std::cout << count << std::endl;
	if (y + height > screenHeight - 25) {
		y = screenHeight - 25 - height;
		hitbox.y = screenHeight - 25 - height;
		vY = 0;
		jump = false;
	}

	characterTimer--;

	if (characterTimer < 0) {
		characterTimer = RUN_TIMER;
	}

	
}

int character::getID() {
	return 1;
}

void character::die() {
	alive = false;
}
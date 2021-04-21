#include "Character.h"
#include <iostream>

#define TOTAL_RUN_FRAMES 50
#define TOTAL_JUMP_FRAMES 60

character::character(double x, double y, double width, double height, double screenWidth, 
					 double screenHeight, SDL_Rect hitbox ,std::vector<GameObjects*>* gameObjects)
					:GameObjects(x, y, width, height, screenWidth, screenHeight, hitbox) 
{
	gravity = -0.8f;
	vY = 0;
	alive = true;
	jump = false;
	this->gameObjects = gameObjects;
	frame = TOTAL_RUN_FRAMES;
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
		if (n >= 58) return 0;
		if (n >= 56) return 1;
		if (n >= 54) return 2;
		if (n >= 52) return 3;
		if (n >= 48) return 4;
		if (n >= 43) return 5;
		if (n >= 38) return 6;
		if (n >= 33) return 7;
		if (n >= 15) return 8;
		if (n >= 9) return 9;
		if (n >= 8) return 10;
		if (n >= 3) return 11;
		if (n >= 2) return 12;
		if (n >= 1) return 13;
		if (n >= 0) return 14;

	}
}

void character::render(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
	switch (clock->gameState) {
	case OPENING_STATE:
	case START_STATE:
	case PAUSE_STATE:
	case GAME_OVER_STATE:
		break;
	case PLAY_STATE:
		SDL_Texture* texture;

		if (jump) {
			texture = resources->getTexture("characterJump", chooseFrames(jump, frame));
		}
		else {
			texture = resources->getTexture("characterRun", chooseFrames(jump, frame));
		}


		//std::cout << "[character] frame:" << chooseFrames(characterTimer) << std::endl;
		int tWidth, tHeight;
		SDL_QueryTexture(texture, NULL, NULL, &tWidth, &tHeight);
		int scale = tWidth / width;
		SDL_Rect dst = {
			x,
			y - 10,
			tWidth / scale,
			tHeight / scale
		};

		SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0,
			NULL, SDL_FLIP_NONE);
		renderHitbox(renderer);
		break;
	}
}



bool character::isAlive() {
	return alive;
}

void character::update(Clock* clock, Inputs *inputs, double velocity, Sound* sound) {
	switch (clock->gameState) {
	case OPENING_STATE:
	case START_STATE:
	case PAUSE_STATE:
	case GAME_OVER_STATE:
		break;
	case PLAY_STATE:
		//std::cout << "[Character] y: " << y << std::endl;
		//std::cout << "[Character] screenHeight - 25 - height: " << screenHeight - 25 - height << std::endl;
		//std::cout << "[Character] vY: " << vY << std::endl;	
		//if (inputs->isKeyDown(SDL_SCANCODE_SPACE)) {  }
		if (y == 525 && vY == 0 && !jump && inputs->isKeyDown(SDL_SCANCODE_SPACE)) { //only jump when on the ground
			vY = 24;
			jump = true;
			count = 0;
			frame = TOTAL_RUN_FRAMES;
		}
		//std::cout << y << std::endl;
		//std::cout << std::boolalpha << jump << std::endl;
		if (jump) {

			if ((y == 525 && vY > 0) || y < 675) {
				y -= vY * clock->deltaT + 0.5f * gravity * clock->deltaT * clock->deltaT;
				hitbox.y -= vY * clock->deltaT + 0.5f * gravity * clock->deltaT * clock->deltaT;
				//y = y0 + v0*t + (a*t*t)/2
				vY += gravity * clock->deltaT;
				//vy = v0 + a*t
				count++;
			}
		}
		//std::cout << count << std::endl;
		if (y > 525) {
			y = 525;
			hitbox.y = 525;
			vY = 0;
			jump = false;
		}
		
		frame--;

		if (frame < 0) {
			frame = TOTAL_RUN_FRAMES;
		}

		//std::cout << TOTAL_RUN_FRAMES / frame << std::endl;
		break;
	}
}

int character::getID() {
	return CHARACTER_ID;
}

void character::die() {
	alive = false;
}
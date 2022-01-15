#include "Character.h"
#include <iostream>

#define TOTAL_RUN_FRAMES 50
#define TOTAL_JUMP_FRAMES 60
#define MAXHEIGHT 330

Character::Character(double x, double y, double width, double height, double screenWidth, 
					 double screenHeight, SDL_Rect hitbox ,std::vector<GameObjects*>* gameObjects)
					:GameObjects(x, y, width, height, screenWidth, screenHeight, hitbox) 
{
	ground = y + height;
	vY = 0;
	alive = true;
	jump = false;
	this->gameObjects = gameObjects;
	frame = TOTAL_RUN_FRAMES;
	fall = true;
}

int Character::chooseFrames() {
	
	if (!jump){
		if (frame == 0) return 9;
		return (TOTAL_RUN_FRAMES - frame) / 5;
	}
	else {
		if (frame >= 58) return 0;
		if (frame >= 56) return 1;
		if (frame >= 54) return 2;
		if (frame >= 52) return 3;
		if (frame >= 48) return 4;
		if (frame >= 43) return 5;
		if (frame >= 38) return 6;
		if (frame >= 33) return 7;
		if (frame >= 15) return 8;
		if (frame >= 9) return 9;
		if (frame >= 8) return 10;
		if (frame >= 3) return 11;
		if (frame >= 2) return 12;
		if (frame >= 1) return 13;
		if (frame >= 0) return 14;

	}
}

void Character::render(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
	switch (clock->gameState) {
	case OPENING_STATE:
	case START_STATE:
	case GAME_OVER_STATE:
		break;
	case PAUSE_STATE:
		//std::cout << "[Character] render" << std::endl;
		break;
	case PLAY_STATE:
		SDL_Texture* texture;

		if (jump) {
			texture = resources->getTexture("characterJump", chooseFrames());
		}
		else {
			texture = resources->getTexture("characterRun", chooseFrames());
		}


		//std::cout << "[Character] frame:" << chooseFrames(CharacterTimer) << std::endl;
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
		// renderHitbox(renderer);
		break;
	}
}



bool Character::isAlive() {
	return alive;
}

void Character::update(Clock* clock, Inputs *inputs, double velocity, Sound* sound) {
	switch (clock->gameState) {
	case OPENING_STATE:
	case START_STATE:
	case PAUSE_STATE:
	case GAME_OVER_STATE:
		break;
	case PLAY_STATE:
		if (y == 525 && vY == 0 && !jump && inputs->isKeyDown(SDL_SCANCODE_SPACE)) { //only jump when on the ground
			vY = 24;
			jump = true;
			frame = TOTAL_JUMP_FRAMES;
			fall = false;
		}
		if (!fall) {
			gameObjects->push_back(new Particle(hitbox.x, y + height/2, -(((double)rand()) / RAND_MAX * 10.0f + 10) * 10.5, 
												(((double)rand()) / RAND_MAX * 30.0f)*2 , 8, "pow"));
		}

		if (jump) {
			if ((y + height == ground && vY > 0) || y < ground) {
				y -= vY * clock->deltaT + 0.5f * gravity * clock->deltaT * clock->deltaT;
				hitbox.y -= vY * clock->deltaT + 0.5f * gravity * clock->deltaT * clock->deltaT;
				//y = y0 + v0*t + (a*t*t)/2
				vY += gravity * clock->deltaT;
				//vy = v0 + a*t
				if (y + height < MAXHEIGHT + height) {
					fall = true;
				}
			}
		}

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


int Character::getID() {
	return CHARACTER_ID;
}

void Character::die() {
}

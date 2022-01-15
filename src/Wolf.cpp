#pragma once
#include "Wolf.h"
#include <iostream>

#define TOTAL_RUN_FRAMES 36
#define TOTAL_JUMP_FRAMES 60
#define X_JUMP 700
#define V_JUMP 24

int Wolf::chooseFrames() {
	if (!jump) {
		if (frame == 0) return 11;
		return (TOTAL_RUN_FRAMES - frame) / 3;
	}
	else {
		if (frame >= 55) return 0;
		if (frame >= 40) return 1;
		if (frame >= 20) return 2;
		if (frame >= 5) return 3;
		if (frame >= 0) return 4;
	}
}

Wolf::Wolf(double x, double y, double width, double height, double screenWidth,
	double screenHeight, bool willJump, SDL_Rect hitbox, std::vector<GameObjects*>* gameObjects)
	:GameObjects(x, y, width, height, screenWidth, screenHeight, hitbox)
{
	ground = y + height;
	frame = TOTAL_RUN_FRAMES;
	alive = true;
	jump = false;
	this->hitbox = hitbox;
	this->gameObjects = gameObjects;
	this->willJump = willJump;
}

void Wolf::render(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
	switch (clock->gameState) {
	case OPENING_STATE:
	case START_STATE:
	case GAME_OVER_STATE:
		break;
	case PAUSE_STATE:
	{
		break;
	}
	case PLAY_STATE:
		SDL_Texture* texture;
		SDL_Rect dst;
		if (jump) {
			texture = resources->getTexture("wolfJump", chooseFrames());
			dst = { (int)(x - 800), (int)(y - 350), (int)(screenWidth + 400), (int)(screenHeight + 400) };
		}
		else {
			texture = resources->getTexture("wolfRun", chooseFrames());
			dst = { (int)x, (int)y, (int)width, (int)height };

		}
		SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0,
			NULL, SDL_FLIP_NONE);
		//renderHitbox(renderer);
		break;
	}
}


void Wolf::update(Clock* clock, Inputs* inputs, double velocity, Sound* sound) {
	switch (clock->gameState) {
	case OPENING_STATE:
	case START_STATE:
	case GAME_OVER_STATE:
		break;
	case PAUSE_STATE:
		break;
	case PLAY_STATE:
	
		if (willJump && !jump && hitbox.x < X_JUMP) {
			vY = V_JUMP;
			jump = true;
			count = 0;
			frame = TOTAL_JUMP_FRAMES;
		}
		
		if (jump) {
			if ((y + height == ground && vY > 0) || y < ground) {
				y -= vY * clock->deltaT + 0.5f * gravity * clock->deltaT * clock->deltaT;
				hitbox.y -= vY * clock->deltaT + 0.5f * gravity * clock->deltaT * clock->deltaT;
				//y = y0 + v0*t + (a*t*t)/2
				vY += gravity * clock->deltaT;
				//vy = v0 + a*t
				count++;
			}
		} else if (willJump && hitbox.x + hitbox.w > screenWidth) {
			gameObjects->push_back(new Particle(screenWidth - 50, screenHeight / 5 * 3, 
				-(((float)rand()) / RAND_MAX * 40.0f -20), -((float)rand()) / RAND_MAX * 40.0f - 20, 6, "danger"));
		}
		if (hitbox.y > 520) {
			y = ground - height;
			hitbox.y = 520;
			vY = 0;
		}

		x -= velocity* clock->deltaT;
		hitbox.x = x + 60;
		if (x + width < 0) {
			alive = false;
		}

		frame--;

		if (frame < 0) {
			frame = TOTAL_RUN_FRAMES;
		}
	}
}

bool Wolf::isAlive() {
	return alive;
}

int Wolf::getID() {
	return THREAT_ID;
}

void Wolf::die() {

}

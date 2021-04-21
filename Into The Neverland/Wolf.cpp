#pragma once
#include "Wolf.h"
#include <iostream>

#define TOTAL_RUN_FRAMES 36

int chooseFrames(int n) {
		if (n >= 33) return 0;
		if (n >= 30) return 1;
		if (n >= 27) return 2;
		if (n >= 24) return 3;
		if (n >= 21) return 4;
		if (n >= 18) return 5;
		if (n >= 15) return 6;
		if (n >= 12) return 7;
		if (n >= 9) return 8;
		if (n >= 6) return 9;
		if (n >= 3) return 10;
		if (n >= 0) return 11;
}

Wolf::Wolf(double x, double y, double width, double height, double screenWidth,
	double screenHeight, SDL_Rect hitbox, std::vector<GameObjects*>* gameObjects)
	:GameObjects(x, y, width, height, screenWidth, screenHeight, hitbox)
{
	frame = TOTAL_RUN_FRAMES;
	alive = true;
	this->hitbox = hitbox;
	this->gameObjects = gameObjects;
}
void Wolf::render(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
	SDL_Texture* texture;
	texture = resources->getTexture("violetWolfRun", chooseFrames(frame));

	SDL_Rect dst = {
		x,
		y,
		width,
		height
	};

	SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0,
		NULL, SDL_FLIP_NONE);
	renderHitbox(renderer);
}


void Wolf::update(Clock* clock, Inputs* inputs, double velocity, Sound* sound) {
	switch (clock->gameState) {
	case OPENING_STATE:
	case START_STATE:
	case PAUSE_STATE:
	case GAME_OVER_STATE:
		break;
	case PLAY_STATE:
		x -= velocity* 1.2;
		//std::cout << x << "_" << velocity << std::endl;
		hitbox.x = x + 60;
		//std::cout << hitbox.x << "_" << velocity << std::endl;
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
	return 2;
}

void Wolf::die() {

}
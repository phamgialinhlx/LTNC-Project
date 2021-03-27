#include "Wall.h"

Wall::Wall(double velocity, double x, double y, double width, double height,
	double screenWidth, double screenHeight, std::vector<GameObjects*>* gameObjects) 
	:GameObjects(x, y, width, height, screenWidth, screenHeight)
{
	this->velocity = velocity;
	alive = true;
	this->gameObjects = gameObjects;
}
void Wall::render(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
	SDL_Texture* texture;
	texture = resources->getTexture("wall", 0);

	SDL_Rect dst = {
		x,
		y,
		width,
		height
	};

	SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0,
		NULL, SDL_FLIP_NONE);
}


void Wall::update(Clock* clock, Inputs* inputs) {
	x -= velocity * clock->getTimeBetweenFrames();
	if (x + width < 0) {
		alive = false;
	}
}

bool Wall::isAlive() {
	return alive;
}

int Wall::getID() {
	return 2;
}

void Wall::die() {

}
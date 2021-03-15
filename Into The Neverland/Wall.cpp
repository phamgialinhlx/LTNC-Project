#include "Wall.h"

Wall::Wall(double velocity, double x, double y, double width, double height,
	double screenWidth, double screenHeight, std::vector<GameObjects*>* gameObjects) 
	:GameObjects(x, y, width, height, screenWidth, screenHeight)
{
	this->velocity = velocity;
	alive = true;
	this->gameObjects = gameObjects;
}
void Wall::render(SDL_Renderer* renderer, Resources* resources, double timeBetweenFrames) {
	SDL_Texture* texture;
	texture = resources->getTexture("wall");

	SDL_Rect dst = {
		x,
		y,
		width,
		height
	};

	SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0,
		NULL, SDL_FLIP_NONE);
}


void Wall::update(double timeBetweenFrames, Inputs* inputs) {
	x -= velocity * timeBetweenFrames;
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
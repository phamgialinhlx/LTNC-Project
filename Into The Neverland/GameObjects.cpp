#include "GameObjects.h"

GameObjects::GameObjects()
{
	texture = NULL;
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

GameObjects::~GameObjects()
{
	free();
}

void GameObjects::free()
{
	if (texture != 0)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
		x = 0;
		y = 0;
		height = 0;
		width = 0;
	}
}


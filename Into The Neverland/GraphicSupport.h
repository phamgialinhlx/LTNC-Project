#pragma once
#ifndef GRAPHIC_SUPPORT
#define GRAPHIC_SUPPORT

#include <SDL.h>
#include "Resources.h"

class GraphicSupport {
private:
	Resources* resources;
	SDL_Renderer* renderer;

	int typeOfAnimation;
	int opacity;
public:

	bool finish;

	GraphicSupport(Resources* resources, SDL_Renderer* renderer);
	void update(int typeOfAnimation);
	void renderTransparentBlackBG();
	void renderNote();

	void render();
};

#endif // !GRAPHIC_SUPPORT

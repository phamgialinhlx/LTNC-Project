#pragma once
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include "Resources.h"
#include "GameObjects.h"
#include "Effects.h"


class Graphics {
private:
	
	Resources* resources;
	SDL_Window* screenWindow;
	SDL_Renderer* renderer;


public:
	const int screenWidth = 1600, screenHeight = 900;
	const std::string windowTitle = "Into The Neverland: 9 + 1 = 11";

	Graphics();
	~Graphics();

	bool initSDL();

	void clearScreen();
	void renderGameObjects(std::vector<GameObjects*>* gameObjects, Clock *clock, Effects *effects);
	void renderAnimation();
	void rendererPresent();
	
};


#endif // !GRAPHICS_H

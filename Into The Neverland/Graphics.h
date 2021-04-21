#pragma once
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
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
	GraphicSupport* graphicSupport;


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
	int getScreenWidth();
	int getScreenHeight();

	GraphicSupport* getGraphicSupport();
};


#endif // !GRAPHICS_H

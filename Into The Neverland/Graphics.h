#pragma once
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <string>
#include <vector>
#include "Resources.h"
#include "GameObjects.h"

class GraphicSupport;

class Graphics {
private:
	
	Resources* resources;
	SDL_Window* screenWindow;
	SDL_Renderer* renderer;
	GraphicSupport* graphicSupport;


public:
	const int screenWidth = 900, screenHeight = 400;
	const std::string windowTitle = "Into The Neverland: 9 + 1 = 11";

	Graphics();
	~Graphics();

	bool initSDL();

	void clearScreen();
	void renderGameObjects(std::vector<GameObjects*>* gameObjects, Clock *clock);
	void renderAnimation();
	void rendererPresent();
	int getScreenWidth();
	int getScreenHeight();

	GraphicSupport* getGraphicSupport();
};


#endif // !GRAPHICS_H

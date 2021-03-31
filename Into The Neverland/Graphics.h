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
	static const int screenWidth, screenHeight;
	static const std::string windowTitle;
	Resources* resources;
	SDL_Window* screenWindow;
	SDL_Renderer* renderer;
	GraphicSupport* graphicSupport;


public:
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
